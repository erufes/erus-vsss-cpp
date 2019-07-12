#ifndef BALL_H
#define BALL_H

/* Nome do módulo: BALL
 * Ano de criação: 2018/10
 * Descrição do módulo: Classe que representa a bola do jogo.
 * 						Possui um vetor de pontos antigos da bola para fazer a predição.
 * 						O método de predição ofensivo desconsidera se a bola está próxima do jogador.
 * Versão: 1.0
 * Pré-requisitos: distâncias positivas
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

		/* previsaoDePosicao
		* Intenção da função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		std::pair<double, double> previsaoDePosicao(){
			return this->Agent::previsaoDePosicao(this->Agent::getPonto(), this->Agent::getxyOld());
		};

	};
}
#endif // BALL_H
