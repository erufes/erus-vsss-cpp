#include "player.h"

Player::Player(int id, double theta ){
    this->theta = theta;
    this->thetaAntigo = theta;
    this->id = id;
}

int Player::getId() const {
		return id;
}

Ponto Player::getPosicaoAntiga() const {
		return posicaoAntiga;
}
void Player::setPosicao(Ponto p){
	this->posicaoAntiga = Agent::getPonto();
	this->update_position(p.getX(), p.getY());
}

double Player::getTheta() const {
		return theta;
}

void Player::setTheta(double theta) {
	this->thetaAntigo = this->theta;
	this->theta = theta;
}

double Player::getThetaAntigo() const {
		return thetaAntigo;
}


