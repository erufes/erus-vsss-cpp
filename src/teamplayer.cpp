#include "teamplayer.h"

TeamPlayer::TeamPlayer(Funcao comportamento, int id,double theta, double distanciaMinDaParede) : Player(id, theta)
{
	this->comportamento = NULL;
	this->mudaComportamento(comportamento);
	this->distanciaMinDaParede = distanciaMinDaParede;
}

Ponto TeamPlayer::movimenta(Ponto posicao, World* mundo){
	return comportamento->movimenta(posicao, mundo);
}

std::pair<int,int> TeamPlayer::controle(Ponto posicao, World* mundo){
	return comportamento->controle(posicao, mundo);
}

void TeamPlayer::mudaComportamento(Funcao novo){
	delete comportamento;
	switch(novo){
		case Goleiro:
			comportamento = new GoleiroBehavior();
			break;
		case Atacante:
			comportamento = new AtaqueBehavior();
			break;
		case Defensor:
			comportamento = new DefesaBehavior();
			break;
	}
}
