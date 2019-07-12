#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"

/* Nome do m�dulo: Player
 * Ano de cria��o: 2018/11
 * Descri��o do m�dulo: cria o player com as posicoes antigas salvas e theta (o agulo referente ao lado inferior do campo)
 * 						Classe Abstrata para que n�o seja instanciada, uma vez que serve de abstra��o de rob�s do time (TeamPlayer) ou inimigos (Enemy).
 * 						Seu funcionamento lembra uma DataClass pois guarda e recupera informa��es como posi��o e id.
 * Vers�o: 1.1
 * Testado!! Selo Valdino de Garantia \0/
 * Pr�-requisitos angulo positivo (0 <= theta >= 2*pi)
 * Membros: Gabriel Valdino, Victor de Oliveira, Lorena Bassani
 */
namespace vsssERUS{
	class Player: public Agent {
		Ponto posicaoAntiga = Ponto(0,0);
		double theta;
		double thetaAntigo;
		int id;
	public:

		Player(int id = 0,double theta = 0.0);

		/* getId
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		int getId() const;

		/* setPosicao
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		void setPosicao(Ponto p);

		/* getPosicaoAntiga
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		Ponto getPosicaoAntiga() const;

		/* getTheta
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		double getTheta() const;

		/* setTheta
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		void setTheta(double theta);

		/* getThetaAntigo
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		double getThetaAntigo() const;

		/* previsaoDePosicao
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		std::pair<double,double> previsaoDePosicao(){
			return this->Agent::previsaoDePosicao();
		}

		/* isEnemy
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		virtual bool isEnemy() = 0;

	};
}
#endif // PLAYER_H
