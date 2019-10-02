#include "world.h"

namespace vsssERUS {

World::World(Campo* campo, TeamPlayer** jogadores, Enemy** inimigos, Ball* bola) {
	this->campo = campo;
	campo->setBall(*bola);
	this->setTeamPlayer(jogadores);
	this->setEnemy(inimigos);
	this->bola = bola;
	for(int i = 0; i < MAX_TEAM_SIZE; i++) {
		atualizacaoCampo.registraObservador(*jogadores[i]);
		jogadores[i]->setCampo(*campo);
	}
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
	return this->jogadores;
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

void World::forceNotify(string s) {
	atualizacaoCampo.notifica();
}

} // vsssERUS