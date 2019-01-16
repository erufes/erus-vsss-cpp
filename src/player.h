#ifndef PLAYER_H
#define PLAYER_H
#include "agent.h"

/* Nome do módulo: Player
 * Ano de criação: 2018/11
 * Descrição do módulo: cria o player com as posicoes antigas salvas e theta (o agulo referente ao lado inferior do campo)
 * 						Classe Abstrata para que não seja instanciada, uma vez que serve de abstração de robôs do time (TeamPlayer) ou inimigos (Enemy).
 * 						Seu funcionamento lembra uma DataClass pois guarda e recupera informações como posição e id.
 * Versão: 1.1
 * Testado!! Selo Valdino de Garantia \0/
 * Pré-requisitos angulo positivo (0 <= theta >= 2*pi)
 * Membros: Gabriel Valdino, Victor de Oliveira, Lorena Bassani
 */

class Player: public Agent {
    Ponto posicaoAntiga = Ponto(0,0);
    double theta;
    double thetaAntigo;
    int id;
public:

    Player(int id = 0,double theta = 0.0);

	int getId() const;

	void setPosicao(Ponto p);

	Ponto getPosicaoAntiga() const;

	double getTheta() const;

	void setTheta(double theta);

	double getThetaAntigo() const;

	std::pair<double,double> previsaoDePosicao(){
		return this->Agent::previsaoDePosicao(this->Agent::getPonto(), this->Agent::getxy_old());
	}

	virtual bool isEnemy() = 0;

};

#endif // PLAYER_H
