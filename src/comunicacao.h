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

	namespace vsssERUS{
	/* Nome do m�dulo: Comunicacao
	* Ano de cria��o: 2018/11
	* Descri��o do m�dulo: Classe que encapsula comunica��o entre o sistema e os robo�s, criada para converter e enviar os dados para o xBEE.
	* Vers�o: 1.1
	* Pr�-requisitos: Porta v�lida em formato COM, ex "COM18"
	* Membros: Ricardo Ramos, Lorena Bassani
	*
	*/

	class Comunicacao
	{

		/* Nome do m�dulo: SerialPort
		* Ano de cria��o: 2016/05
		* Descri��o do m�dulo: M�dulo que implementa comunica��o serial no Windows.
		* 						fonte: https://gist.github.com/manashmndl/72e96ed2c051726ce1433ede9d6a0f4c
		* Pr�-requisitos: Ambiente Windows e Porta v�lida em formato COM
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

		/* Destrutor de comunica��o
		* Inten��o da fun��o: Finalizar a comunica��o de forma segura
		* Pr�-requisitos: Nenhum
		* Efeitos Colaterais: Fecha a porta serial e libera o espa�o utilizado por SerialPort e Comunica��o.
		* Parametros: Nenhum
		* Retorno: N�o possui retorno
		*/
		~Comunicacao(){
			delete com;
		}

		/* sendCommand
		* Inten��o da fun��o: Enviar os dados para o xBEE
		* Pr�-requisitos: Id do rob� entre {1,2,3}, cmd v�lido e valor entre 0 a 255
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando, comando do rob� e valor que deve ser colocado nas rodas
		* Retorno: N�o possui retorno
		*/
		void sendCommand(int robotId, char cmdId, int value);

		/* conectado
		* Inten��o da fun��o: Verificar se a porta est� conectada
		* Pr�-requisitos: Possuir uma porta
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: N�o possui parametro
		* Retorno: Retorna true se estiver conectado e false caso contr�rio
		*/
		bool conectado();

		/* stop
		* Inten��o da fun��o: Atalho para enviar os dados de parada para o rob� alvo
		* Pr�-requisitos: Id do rob� entre {1,2,3}
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando de parada
		* Retorno: N�o possui retorno
		*/
		void stop(int robotId);

		/* set_speed_right
		* Inten��o da fun��o: Atalho para enviar os dados de movimenta��o da roda direita do rob� alvo
		* Pr�-requisitos: Id do rob� entre {1,2,3}
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando de movimenta��o, velocidade de movimenta��o do rob�
		* Retorno: N�o possui retorno
		*/
		void set_speed_right(int robotId, int speed);

		/* set_pwm_right
		* Inten��o da fun��o: Atalho para enviar os dados de movimenta��o pwm da roda direita do rob� alvo
		* Pr�-requisitos: Id do rob� entre {1,2,3}
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando de movimenta��o, velocidade de movimenta��o do rob�
		* Retorno: N�o possui retorno
		*/
		void set_pwm_right(int robotId, int speed);

		/* set_speed_left
		* Inten��o da fun��o: Atalho para enviar os dados de movimenta��o da roda esquerda do rob� alvo
		* Pr�-requisitos: Id do rob� entre {1,2,3}
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando de movimenta��o, velocidade de movimenta��o do rob�
		* Retorno: N�o possui retorno
		*/
		void set_speed_left(int robotId, int speed);

		/* set_pwm_right
		* Inten��o da fun��o: Atalho para enviar os dados de movimenta��o pwm da roda esquerda do rob� alvo
		* Pr�-requisitos: Id do rob� entre {1,2,3}
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Id do rob� que receber� o comando de movimenta��o, velocidade de movimenta��o do rob�
		* Retorno: N�o possui retorno
		*/
		void set_pwm_left(int robotId, int speed);

	};
}
#endif // CAMPO_H
