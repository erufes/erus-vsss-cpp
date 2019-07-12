#include "player.h"


vsssERUS::Player::Player(int id, double theta ){
    this->theta = theta;
    this->thetaAntigo = theta;
    this->id = id;
}

int vsssERUS::Player::getId() const {
		return id;
}

vsssERUS::Ponto vsssERUS::Player::getPosicaoAntiga() const {
		return posicaoAntiga;
}
void vsssERUS::Player::setPosicao(Ponto p){
	this->posicaoAntiga = Agent::getPonto();
	this->updatePosition(p.getX(), p.getY());
}

double vsssERUS::Player::getTheta() const {
		return theta;
}

void vsssERUS::Player::setTheta(double theta) {
	this->thetaAntigo = this->theta;
	this->theta = theta;
}

double vsssERUS::Player::getThetaAntigo() const {
		return thetaAntigo;
}