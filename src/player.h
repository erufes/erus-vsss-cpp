#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"

/* Nome do módulo: Player
 * Ano de criação: 2018/11
 * Descrição do módulo: Cria o player com as posições antigas salvas e theta (o ângulo referente ao lado inferior do campo)
 * 						Classe Abstrata para que não seja instanciada, uma vez que serve de abstração de robôs do time (TeamPlayer) ou inimigos (Enemy).
 * 						Seu funcionamento lembra uma DataClass pois guarda e recupera informações como posição e id.
 * Versão: 1.1
 * Testado!! Selo Valdino de Garantia \0/
 * Pré-requisitos: Ângulo positivo (0 <= theta >= 2*pi)
 * Membros: Gabriel Valdino, Victor de Oliveira, Lorena Bassani
 */

namespace vsssERUS{
	class Player: public Agent {
		double theta;
		double thetaAntigo;
		int id;
	public:

		Player(int id = 0,double theta = 0.0);

		/* getId
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		int getId() const;

		/* getPosicaoAntiga
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Ponto getPosicaoAntiga() const;

		/* getTheta
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		double getTheta() const;

		/* setTheta
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		void setTheta(double theta);

		/* getThetaAntigo
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		double getThetaAntigo() const;

		/* isEnemy
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		virtual bool isEnemy() = 0;

	};
}
#endif // PLAYER_H
