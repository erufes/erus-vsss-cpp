/*
 * defesabehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "defesabehavior.h"

vsssERUS::DefesaBehavior::DefesaBehavior() {}
vsssERUS::DefesaBehavior::~DefesaBehavior() {}

vsssERUS::Ponto vsssERUS::DefesaBehavior::movimenta(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	return vsssERUS::Ponto();
}

std::pair<int,int> vsssERUS::DefesaBehavior::controle(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	return std::pair<int,int>();
}
std::pair<int,int> vsssERUS::DefesaBehavior::sairDaParede(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
	return std::pair<int, int>();
}

std::pair<int,int> vsssERUS::DefesaBehavior::evitarColisaoEntreJogadores(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
	return std::pair<int, int>();
}
