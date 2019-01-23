#ifndef BALL_H
#define BALL_H
/* Nome do m�dulo: BALL
 * Ano de cria��o: 2018/10
 * Descri��o do m�dulo: Classe que representa a bola do jogo.
 * 						Possui um vetor de pontos antigos da bola para fazer a predi��o
 * 						O metodo de predi�ao ofensivo desconsidera se a bola esta proxima do jogador.
 * Vers�o: 1.0
 * Pr�-requisitos: distancias positivas
 * Membros: Lorena Bassani, Victor de Oliveira
 */
#include "agent.h"
#include <vector>
#include <iostream>

namespace vsssERUS{
	class Ball: public Agent
	{

	public:
		Ball(double x, double y);
		Ball(Ponto p);

	//    Ponto predict_ball_method(Player* jogador);
	//    Ponto predict_ball_method_ofensive(Player* jogador);

		/* previsaoDePosicao
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		std::pair<double, double> previsaoDePosicao(){
			return this->Agent::previsaoDePosicao(this->Agent::getPonto(), this->Agent::getxy_old());
		};

	};
}
#endif // BALL_H
