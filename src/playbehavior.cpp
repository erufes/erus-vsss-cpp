/*
 * playbehavior.cpp
 *
 *  Created on: 8 de jan de 2019
 *      Author: ERUS
 */

#include "playbehavior.h"

PlayBehavior::PlayBehavior(){};

PlayBehavior::~PlayBehavior(){};

Ponto PlayBehavior::movimenta(Ponto posicao, World* mundo){
	return Ponto(0,0);
}

std::pair<int,int> PlayBehavior::controle(Ponto posicao, World* mundo){
	return std::pair<int,int>();
}

std::pair<int,int> PlayBehavior::sairDaParede(Ponto posicao, World* mundo){

	//todo: implementar sairDaParede
	return std::pair<int,int>();
}


std::pair<int,int> PlayBehavior::evitarColisaoEntreJogadores(Ponto posicao, World* mundo){
	//todo: implementar evitarColisaoEntreJogadores
	return std::pair<int,int>();
}
