#include "team.h"


vsssERUS::Team::Team() {
}

vsssERUS::Team::~Team(){ 

}

void vsssERUS::Team::adicionaAoTime(Player& p) {
	if(this->jogadores.size() < MAX_TEAM_SIZE) {
		this->jogadores.push_back(&p);
	}
	return;
}