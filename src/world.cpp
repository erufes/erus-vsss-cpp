#include "world.h"

World::World(Campo* campo, TeamPlayer** jogadores, Enemy** inimigos, Ball* bola) {
	this->campo = campo;
	this->bola = bola;
	// TODO Auto-generated constructor stub

}

World::~World() {
	// TODO Auto-generated destructor stub
}

void World::setBall(Ball* bola){
	this->bola = bola;
}

Ball* World::getBall(){
	return bola;
}

void World::setTeamPlayer(TeamPlayer** jogadores){
	for(int i = 0; i < 3; i++) this->jogadores[i] = jogadores[i];
}

TeamPlayer** World::getTeamPlayer(){
	return jogadores;
}

void World::setEnemy(Enemy** inimigos){
	for(int i = 0; i < 3; i++) this->inimigos[i] = inimigos[i];
}

Enemy** World::getEnemy(){
	return inimigos;
}

void World::setCampo(Campo* campo){
	this->campo = campo;
}

Campo* World::getCampo(){
	return campo;
}

