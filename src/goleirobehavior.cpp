/*
 * goleirobehavior.cpp
 *
 *  Created on: 10 de dez de 2018
 *      Author: ERUS
 */

#include "goleirobehavior.h"
#include "world.h"
#include <cmath>

vsssERUS::GoleiroBehavior::GoleiroBehavior() {

}

vsssERUS::Ponto vsssERUS::GoleiroBehavior::movimenta(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	/* Ideia da implementação :
	 * 	Posicionar o robô de forma que ele impessa a trajetória da bola
	 * 		Como : 	Calcular o angulo de abertura entre a bola e o gol
	 * 				Posicionar o robô onde o "triangulo" tenha base de 7,5 (tamanho do robô)
	 */

	//TODO: implementar vsssERUS::GoleiroBehavior::movimenta
	Ponto ballPosition = (mundo->getBall()->getPosicao());
	// a² = b² + c² - 2bc.cos α 
	// float alfa = acos(thisThingUpHere);
	return Ponto();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::controle(vsssERUS::Ponto posicao, vsssERUS::World* mundo){
	//TODO: implementar vsssERUS::GoleiroBehavior::controle
	return std::pair<int,int>();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::evitarColisaoEntreJogadores(vsssERUS::Ponto posicao, vsssERUS::World* mundo) {
	return std::pair<int, int>();
}

std::pair<int,int> vsssERUS::GoleiroBehavior::sairDaParede(Ponto posicao, World* mundo) {
	return std::pair<int, int>();
}

