/*
 * goleirobehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "goleirobehavior.h"
namespace vsssERUS {

GoleiroBehavior::GoleiroBehavior() {

}

Ponto GoleiroBehavior::movimenta(Ponto posicao, World* mundo){
	//todo: implementar GoleiroBehavior::movimenta
	return Ponto();
}

std::pair<int,int> GoleiroBehavior::controle(Ponto posicao, World* mundo){
	//todo: implementar GoleiroBehavior::controle
	return std::pair<int,int>();
}

std::pair<int,int> GoleiroBehavior::evitarColisaoEntreJogadores(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

std::pair<int,int> GoleiroBehavior::sairDaParede(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

}