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
#include "player.h"
#include <vector>
#include <iostream>

class Ball: public Agent
{
    vector<Ponto> old;
public:
    Ball(double x, double y);
    vector<Ponto> getxy_old();
    Ponto predict_ball_method(Player* jogador);
    Ponto predict_ball_method_ofensive(Player* jogador);
    void set_position(double x, double y);
    std::pair<double, double> predicao_adaptativa(){
    	return this->Agent::predicao_adaptativa(this->Agent::getPonto(), this->old);
    };

};

#endif // BALL_H
