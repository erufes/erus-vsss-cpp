#include "player.h"

namespace vsssERUS{

    Player::Player(int id, double theta){
        this->theta = theta;
        this->thetaAntigo = theta;
        this->id = id;
    }

    int Player::getId() const {
            return id;
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
}