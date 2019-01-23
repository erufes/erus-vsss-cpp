#include "teamplayer.h"

vsssERUS::TeamPlayer::TeamPlayer(Funcao comportamento, int id,double theta, double distanciaMinDaParede) : Player(id, theta)
{
	this->comportamento = NULL;
	this->mudaComportamento(comportamento);
	this->distanciaMinDaParede = distanciaMinDaParede;
}

vsssERUS::Ponto vsssERUS::TeamPlayer::movimenta(vsssERUS::Ponto posicao, World* mundo){
	return comportamento->movimenta(posicao, mundo);
}

std::pair<int,int> vsssERUS::TeamPlayer::controle(vsssERUS::Ponto posicao, World* mundo){
	return comportamento->controle(posicao, mundo);
}

void vsssERUS::TeamPlayer::mudaComportamento(Funcao novo){
	if (comportamento != NULL) delete comportamento;
	switch(novo){
		case Goleiro:
			comportamento = new vsssERUS::GoleiroBehavior();
			break;
		case Atacante:
			comportamento = new vsssERUS::AtaqueBehavior();
			break;
		case Defensor:
			comportamento = new vsssERUS::DefesaBehavior();
			break;
	}
}
