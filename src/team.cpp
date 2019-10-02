#include "team.h"

namespace vsssERUS {

Team::Team() {
}

Team::~Team(){ 

}

void Team::adicionaAoTime(Player& p) {
	if(this->jogadores.size() < MAX_TEAM_SIZE) {
		this->jogadores.push_back(&p);
	}
	return;
}

} // vsssERUS