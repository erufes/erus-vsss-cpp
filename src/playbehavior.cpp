/*
 * playbehavior.cpp
 *
 *  Created on: 8 de jan de 2019
 *      Author: ERUS
 */

#include "playbehavior.h"


vsssERUS::PlayBehavior::PlayBehavior(){};

vsssERUS::PlayBehavior::~PlayBehavior(){};

vsssERUS::Ponto vsssERUS::PlayBehavior::movimenta(){
	return Ponto(0,0);
}

std::pair<int,int> vsssERUS::PlayBehavior::controle(){
	return std::pair<int,int>();
}

std::pair<int,int> vsssERUS::PlayBehavior::sairDaParede(){

	//todo: implementar sairDaParede
	return std::pair<int,int>();
}


std::pair<int,int> vsssERUS::PlayBehavior::evitarColisaoEntreJogadores(){
	//todo: implementar evitarColisaoEntreJogadores
	return std::pair<int,int>();
}
