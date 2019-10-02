/*
 * goleirobehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "goleirobehavior.h"

vsssERUS::GoleiroBehavior::GoleiroBehavior() {

}

vsssERUS::Ponto vsssERUS::GoleiroBehavior::movimenta(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	//todo: implementar vsssERUS::GoleiroBehavior::movimenta
	return Ponto();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::controle(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	//todo: implementar vsssERUS::GoleiroBehavior::controle
	return std::pair<int,int>();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::evitarColisaoEntreJogadores(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
	return std::pair<int, int>();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::sairDaParede(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

