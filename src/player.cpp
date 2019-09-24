#include "player.h"


vsssERUS::Player::Player(int id, double theta){
    this->theta = theta;
    this->thetaAntigo = theta;
    this->id = id;
}

int vsssERUS::Player::getId() const {
		return id;
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