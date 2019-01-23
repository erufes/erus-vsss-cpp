/*
 * playbehavior.cpp
 *
 *  Created on: 8 de jan de 2019
 *      Author: ERUS
 */

#include "playbehavior.h"


vsssERUS::PlayBehavior::PlayBehavior(){};

vsssERUS::PlayBehavior::~PlayBehavior(){};

vsssERUS::Ponto vsssERUS::PlayBehavior::movimenta(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	return Ponto(0,0);
}

std::pair<int,int> vsssERUS::PlayBehavior::controle(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	return std::pair<int,int>();
}

std::pair<int,int> vsssERUS::PlayBehavior::sairDaParede(vsssERUS::Ponto posicao, vsssERUS::World* mundo){

	//todo: implementar sairDaParede
	return std::pair<int,int>();
}


std::pair<int,int> vsssERUS::PlayBehavior::evitarColisaoEntreJogadores(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	//todo: implementar evitarColisaoEntreJogadores
	return std::pair<int,int>();
}
