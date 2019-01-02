/*
 * world.cpp
 *
 *  Created on: 2 de jan de 2019
 *      Author: ERUS
 */

#include "world.h"

World::World(Campo campo, vector<TeamPlayer> jogadores, vector<Enemy> inimigos, Ball bola) {
	this->campo = campo;
	this->bola = bola;
	this->jogadores = jogadores;
	this->inimigos = inimigos;
	// TODO Auto-generated constructor stub

}

World::~World() {
	// TODO Auto-generated destructor stub
}

void World::setBall(Ball bola){
	this->bola = bola;
}

Ball World::getBall(){
	return bola;
}

void World::setTeamPlayer(vector<TeamPlayer> jogadores){
	this->jogadores = jogadores;
}

vector<TeamPlayer> World::getTeamPlayer(){
	return jogadores;
}

void World::setEnemy(vector<Enemy> inimigos){
	this->inimigos = inimigos;
}

vector<Enemy> World::getEnemy(){
	return inimigos;
}

void World::setCampo(Campo campo){
	this->campo = campo;
}

Campo World::getCampo(){
	return campo;
}

