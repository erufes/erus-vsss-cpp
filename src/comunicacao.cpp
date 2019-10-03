#ifdef RunningOnWindows
    #include "comunicacao.h"

    vsssERUS::Comunicacao::Comunicacao(string porta){
        //Converte para o formato que a biblioteca l� a porta
        porta = "\\\\.\\" + porta;

        //Abre a porta
        this->com = new SerialPort((char*)porta.c_str());
    }

    void vsssERUS::Comunicacao::sendCommand(int robotId, char cmdId, int value){
        string leitura;
        stringstream ss;

        //Converte todos os valores para stringstream
        ss << (char)0 << (char) robotId << cmdId << (char)value;

        //Converte a stringstream em string para que possa ser passada como par�metro do m�todo que envia os dados
        leitura = ss.str();

        //Passa os dados e seu tamanho para o m�todo de envio
        com->writeSerialPort((char*)leitura.c_str(), leitura.size());
        //cout << "Valor enviado: " << leitura << endl;
    }

    bool vsssERUS::Comunicacao::conectado(){
        //Verifica se a porta est� conectada
        return com->isConnected();
    }

    void vsssERUS::Comunicacao::set_speed_right(int robotId, int speed){
        if(speed > 255)
            speed = 255;
        if(speed < -255)
            speed = -255;
        sendCommand(robotId, 'r', speed/2+128);
    }

    void vsssERUS::Comunicacao::set_pwm_right(int robotId, int speed){
        if(speed > 255)
            speed = 255;
        if(speed < -255)
            speed = -255;
        sendCommand(robotId, 'R', speed/2+128);
    }

    void vsssERUS::Comunicacao::set_speed_left(int robotId, int speed){
        if(speed > 255)
            speed = 255;
        if(speed < -255)
            speed = -255;
        sendCommand(robotId, 'l', speed/2+128);
    }

    void vsssERUS::Comunicacao::set_pwm_left(int robotId, int speed){
        if(speed > 255)
            speed = 255;
        if(speed < -255)
            speed = -255;
        sendCommand(robotId, 'L', speed/2+128);
    }

    void vsssERUS::Comunicacao::stop(int robotId){
        sendCommand(robotId, 's', 128);
    }

    vsssERUS::Comunicacao::SerialPort::SerialPort(char *portName)
    {
        this->connected = false;

        this->handler = CreateFileA(static_cast<LPCSTR>(portName),
                                    GENERIC_READ | GENERIC_WRITE,
                                    0,
                                    NULL,
                                    OPEN_EXISTING,
                                    FILE_ATTRIBUTE_NORMAL,
                                    NULL);
        if (this->handler == INVALID_HANDLE_VALUE){
            if (GetLastError() == ERROR_FILE_NOT_FOUND){
                printf("ERROR: Handle was not attached. Reason: %s not available\n", portName);
            }
        else
            {
                //todo: mudar para exce��o
                printf("ERROR!!!");
            }
        }
        else {
            DCB dcbSerialParameters = {0};

            if (!GetCommState(this->handler, &dcbSerialParameters)) {
                //todo: mudar para exce��o
                printf("failed to get current serial parameters");
            }
            else {
                dcbSerialParameters.BaudRate = CBR_4800;
                dcbSerialParameters.ByteSize = 8;
                dcbSerialParameters.StopBits = ONESTOPBIT;
                dcbSerialParameters.Parity = NOPARITY;
                dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

                if (!SetCommState(handler, &dcbSerialParameters))
                {
                    //todo: mudar para exce��o
                    printf("ALERT: could not set Serial port parameters\n");
                }
                else {
                    this->connected = true;
                    PurgeComm(this->handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
                    Sleep(ARDUINO_WAIT_TIME);
                }
            }
        }
        errors = 0;
    }

    vsssERUS::Comunicacao::SerialPort::~SerialPort()
    {
        if (this->connected){
            this->connected = false;
            CloseHandle(this->handler);
            printf("Fechando a porta..\n");
        }
    }

    int vsssERUS::Comunicacao::SerialPort::readSerialPort(char *buffer, unsigned int buf_size)
    {
        DWORD bytesRead;
        unsigned int toRead;

        ClearCommError(this->handler, &this->errors, &this->status);

        if (this->status.cbInQue > 0){
            if (this->status.cbInQue > buf_size){
                toRead = buf_size;
            }
            else toRead = this->status.cbInQue;
        }

        if (ReadFile(this->handler, buffer, toRead, &bytesRead, NULL)) return bytesRead;

        return 0;
    }

    bool vsssERUS::Comunicacao::SerialPort::writeSerialPort(char *buffer, unsigned int buf_size)
    {
        DWORD bytesSend;

        if (!WriteFile(this->handler, (void*) buffer, buf_size, &bytesSend, 0)){
            ClearCommError(this->handler, &this->errors, &this->status);
            return false;
        }
        else return true;
    }

    bool vsssERUS::Comunicacao::SerialPort::isConnected()
    {
        return this->connected;
    }
#endif