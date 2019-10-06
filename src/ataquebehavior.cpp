/*
 *  ataquebehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "ataquebehavior.h"

namespace vsssERUS{

    AtaqueBehavior::AtaqueBehavior() {}


    AtaqueBehavior::~AtaqueBehavior() { return; }


    Ponto AtaqueBehavior::movimenta(Ponto posicao, World* mundo){
        // TODO: Implementar AtaqueBehaviour
        return Ponto();
    }


    std::pair<int,int> AtaqueBehavior::controle(Ponto posicao, World* mundo){
        return pair<int,int>();
    }


    std::pair<int,int> AtaqueBehavior::sairDaParede(Ponto posicao, World* mundo) {
        return pair<int, int>();
    }


    std::pair<int,int> AtaqueBehavior::evitarColisaoEntreJogadores(Ponto posicao, World* mundo) {
        return pair<int, int>();
    }
}