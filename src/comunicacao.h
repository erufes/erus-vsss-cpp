#ifndef COMUNICACAO_H
#define COMUNICACAO_H
#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>

using namespace std;

/* Nome do módulo: Comunicacao
 * Ano de criação: 2018/11
 * Descrição do módulo: Classe que encapsula comunicação entre o sistema e os roboôs, criada para converter e enviar os dados para o xBEE.
 * Versão: 1.1
 * Pré-requisitos: Porta válida em formato COM, ex "COM18"
 * Membros: Ricardo Ramos, Lorena Bassani
 *
 */

class Comunicacao
{

	/* Nome do módulo: SerialPort
	 * Ano de criação: 2016/05
	 * Descrição do módulo: Módulo que implementa comunicação serial no Windows.
	 * 						fonte: https://gist.github.com/manashmndl/72e96ed2c051726ce1433ede9d6a0f4c
	 * Pré-requisitos: Ambiente Windows e Porta válida em formato COM
	 */
	class SerialPort
	{
	private:
		HANDLE handler;
		bool connected;
		COMSTAT status;
		DWORD errors;
	public:
		SerialPort(char *portName);
		~SerialPort();

		int readSerialPort(char *buffer, unsigned int buf_size);
		bool writeSerialPort(char *buffer, unsigned int buf_size);
		bool isConnected();
	};
	SerialPort* com;
public:
    Comunicacao(string porta);

    /* Destrutor de comunicação
     * Intenção da função: Finalizar a comunicação de forma segura
     * Pré-requisitos: Nenhum
     * Efeitos Colaterais: Fecha a porta serial e libera o espaço utilizado por SerialPort e Comunicação.
     * Parametros: Nenhum
     * Retorno: Não possui retorno
     */
	~Comunicacao(){
		delete com;
	}

    /* sendCommand
     * Intenção da função: Enviar os dados para o xBEE
     * Pré-requisitos: Id do robô entre {1,2,3}, cmd válido e valor entre 0 a 255
     * Efeitos colaterais: Não possui efeitos colaterais
     * Parametros: Id do robô que receberá o comando, comando do robô e valor que deve ser colocado nas rodas
     * Retorno: Não possui retorno
     */
    void sendCommand(int robotId, char cmdId, int value);

    /* conectado
	 * Intenção da função: Verificar se a porta está conectada
	 * Pré-requisitos: Possuir uma porta
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Não possui parametro
	 * Retorno: Retorna true se estiver conectado e false caso contrário
	 */
    bool conectado();

    /* stop
	 * Intenção da função: Atalho para enviar os dados de parada para o robô alvo
	 * Pré-requisitos: Id do robô entre {1,2,3}
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Id do robô que receberá o comando de parada
	 * Retorno: Não possui retorno
	 */
    void stop(int robotId);

    /* set_speed_right
	 * Intenção da função: Atalho para enviar os dados de movimentação da roda direita do robô alvo
	 * Pré-requisitos: Id do robô entre {1,2,3}
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Id do robô que receberá o comando de movimentação, velocidade de movimentação do robô
	 * Retorno: Não possui retorno
	 */
    void set_speed_right(int robotId, int speed);

    /* set_pwm_right
	 * Intenção da função: Atalho para enviar os dados de movimentação pwm da roda direita do robô alvo
	 * Pré-requisitos: Id do robô entre {1,2,3}
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Id do robô que receberá o comando de movimentação, velocidade de movimentação do robô
	 * Retorno: Não possui retorno
	 */
    void set_pwm_right(int robotId, int speed);

    /* set_speed_left
	 * Intenção da função: Atalho para enviar os dados de movimentação da roda esquerda do robô alvo
	 * Pré-requisitos: Id do robô entre {1,2,3}
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Id do robô que receberá o comando de movimentação, velocidade de movimentação do robô
	 * Retorno: Não possui retorno
	 */
    void set_speed_left(int robotId, int speed);

    /* set_pwm_right
	 * Intenção da função: Atalho para enviar os dados de movimentação pwm da roda esquerda do robô alvo
	 * Pré-requisitos: Id do robô entre {1,2,3}
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Id do robô que receberá o comando de movimentação, velocidade de movimentação do robô
	 * Retorno: Não possui retorno
	 */
    void set_pwm_left(int robotId, int speed);

};

#endif // CAMPO_H
