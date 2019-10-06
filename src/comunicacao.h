#ifndef COMUNICACAO_H
#define COMUNICACAO_H

/* Nome do m�dulo: Comunicacao
* Ano de cria��o: 2018/11
* Descri��o do m�dulo: Classe que encapsula comunica��o entre o sistema e os robo�s, criada para converter e enviar os dados para o xBEE.
* Vers�o: 1.1
* Pr�-requisitos: Porta v�lida em formato COM, ex "COM18"
* Membros: Ricardo Ramos, Lorena Bassani
*
*/

#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255
#define RunningOnLinux
#undef RunningOnWindows

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>


using namespace std;

namespace vsssERUS{


	class Comunicacao {

	#ifdef RunningOnWindows
		/* Nome do módulo : 		SerialPort
		 * Ano de criação : 		2016/05
		 * Descrição do módulo : 	Módulo que implementa comunicaçãoo serial no Windows.
		 * 							fonte: https://gist.github.com/manashmndl/72e96ed2c051726ce1433ede9d6a0f4c
		 * Pré-requisitos : 		Ambiente Windows (RunningOnWindows Defined)
		 */
		#include <windows.h>
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
	#endif // RunningOnWindows

	#ifdef RunningOnLinux
		// TODO : Implementar comuniação em Linux
	#endif //RunningOnLinux

		SerialPort* com;
	public:
		Comunicacao(string porta);

		/* Nome da Função :		 	~Comunicacao (Destrutor de comunicação)
		 * Intenção da função : 	Finalizar a comunica��o de forma segura
		 * Pré-requisitos : 		Nenhum
		 * Efeitos Colaterais : 	Fecha a porta serial e libera o espaço utilizado por SerialPort e Comunica��o.
		 * Parametros : 			Nenhum
		 * Retorno : 				Nenhum
		 */
		~Comunicacao(){
			delete com;
		}

		/* Nome da Função : 	sendCommand
		 * Intenção da função : Enviar os dados para o xBEE
		 * Pré-requisitos : 	Id de um robô em campo
		 * 						cmd válido
		 * 						valor entre 0 a 255
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : 	Id do robô que receberá o comando
		 * 						char : 	comando do robô
		 * 						int : 	valor que deve ser colocado nas rodas
		 * Retorno : 			Nenhum
		 */
		void sendCommand(int robotId, char cmdId, int value);

		/* Nome da Função : 	conectado
		 * Intenção da função : Verificar se a porta está conectada
		 * Pré-requisitos : 	Possuir uma porta
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		Nenhum
		 * Retorno: 			bool : true se estiver conectado e false caso contrário
		 */
		bool conectado();

		/* Nome da Função :		stop
		 * Intenção da função : Atalho para enviar os dados de parada para o robô alvo
		 * Pré-requisitos : 	Id de um robô em campo
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : Id do robô que receberá o comando de parada
		 * Retorno : 			Nenhum
		 */
		void stop(int robotId);

		/* Nome da Função : 	set_speed_right
		 * Intenção da função : Atalho para enviar os dados de movimentação da roda direita do robô alvo
		 * Pré-requisitos : 	Id de um robô em campo
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : Id do robô que receberá o comando
		 * 						int : velocidade de movimentação do robô
		 * Retorno: 			Nenhum
		 */
		void set_speed_right(int robotId, int speed);

		/* Nome da Função : 	set_pwm_right
		 * Intenção da função : Atalho para enviar os dados de movimentação da roda direita do robô alvo
		 * Pré-requisitos : 	Id de um robô em campo
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : Id do robô que receberá o comando
		 * 						int : sinal PWM de movimentação do robô
		 * Retorno: 			Nenhum
		 */
		void set_pwm_right(int robotId, int speed);

		/* Nome da Função : 	set_speed_left
		 * Intenção da função : Atalho para enviar os dados de movimentação da roda esquerda do robô alvo
		 * Pré-requisitos : 	Id de um robô em campo
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : Id do robô que receberá o comando
		 * 						int : velocidade de movimentação do robô
		 * Retorno: 			Nenhum
		 */
		void set_speed_left(int robotId, int speed);

		/* Nome da Função : 	set_pwm_left
		 * Intenção da função : Atalho para enviar os dados de movimentação da roda esquerda do robô alvo
		 * Pré-requisitos : 	Id de um robô em campo
		 * Efeitos colaterais : Nenhum
		 * Parametros : 		int : Id do robô que receberá o comando
		 * 						int : sinal PWM de movimentação do robô
		 * Retorno: 			Nenhum
		 */
		void set_pwm_left(int robotId, int speed);

	};
}
#endif // CAMPO_H
