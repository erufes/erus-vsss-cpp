/*
 * defesabehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "defesabehavior.h"

namespace vsssERUS {

DefesaBehavior::DefesaBehavior() {}
DefesaBehavior::~DefesaBehavior() {}

Ponto DefesaBehavior::movimenta(Ponto posicao, World* mundo){
	return Ponto();
}

std::pair<int,int> DefesaBehavior::controle(Ponto posicao, World* mundo){
	return std::pair<int,int>();
}
std::pair<int,int> DefesaBehavior::sairDaParede(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

std::pair<int,int> DefesaBehavior::evitarColisaoEntreJogadores(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

} // vsssERUS