#include "world.h"

vsssERUS::World::World(Campo* campo, TeamPlayer** jogadores, Enemy** inimigos, Ball* bola) {
	this->campo = campo;
	campo->setBall(*bola);
	this->setTeamPlayer(jogadores);
	this->setEnemy(inimigos);
	this->bola = bola;
	for(int i = 0; i < MAX_TEAM_SIZE; i++) {
		n.registraObservador(*jogadores[i]);
		jogadores[i]->setCampo(*campo);
	}
}

vsssERUS::World::~World() {
	// TODO Auto-generated destructor stub
}

void vsssERUS::World::setBall(Ball* bola){
	this->bola = bola;
}

vsssERUS::Ball* vsssERUS::World::getBall(){
	return bola;
}

void vsssERUS::World::setTeamPlayer(TeamPlayer** jogadores){
	for(int i = 0; i < 3; i++) this->jogadores[i] = jogadores[i];
}

vsssERUS::TeamPlayer** vsssERUS::World::getTeamPlayer(){
	return this->jogadores;
}

void vsssERUS::World::setEnemy(Enemy** inimigos){
	for(int i = 0; i < 3; i++) this->inimigos[i] = inimigos[i];
}

vsssERUS::Enemy** vsssERUS::World::getEnemy(){
	return inimigos;
}

void vsssERUS::World::setCampo(Campo* campo){
	this->campo = campo;
}

vsssERUS::Campo* vsssERUS::World::getCampo(){
	return campo;
}

void vsssERUS::World::forceNotify(string s) {
	n.notifica();
}