#include "teamplayer.h"

TeamPlayer::TeamPlayer(Funcao comportamento, int id,double theta, double distanciaMinDaParede) : Player(id, theta)
{
	mudaComportamento(comportamento);
	this->distanciaMinDaParede = distanciaMinDaParede;

}

//Ponto TeamPlayer::movimenta(Ponto posicao){
//	return comportamento.movimenta(posicao);
//}

//std::pair<int,int> TeamPlayer::controle(Ponto posicao){
//	return comportamento.controle(posicao);
//}

void TeamPlayer::mudaComportamento(Funcao novo){
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
