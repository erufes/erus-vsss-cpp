#ifndef BALL_H
#define BALL_H
/* Nome do módulo: BALL
 * Ano de criação: 2018/10
 * Descrição do módulo: Classe que representa a bola do jogo.
 * 						Possui um vetor de pontos antigos da bola para fazer a predição
 * 						O metodo de prediçao ofensivo desconsidera se a bola esta proxima do jogador.
 * Versão: 1.0
 * Pré-requisitos: distancias positivas
 * Membros: Lorena Bassani, Victor de Oliveira
 */
#include "agent.h"
//#include "player.h"
#include <vector>
#include <iostream>

class Ball: public Agent
{

public:
    Ball(double x, double y);
    Ball(Ponto p);

//    Ponto predict_ball_method(Player* jogador);
//    Ponto predict_ball_method_ofensive(Player* jogador);

    /* previsaoDePosicao
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    std::pair<double, double> previsaoDePosicao(){
    	return this->Agent::previsaoDePosicao(this->Agent::getPonto(), this->Agent::getxy_old());
    };

};

#endif // BALL_H
