#include "world.h"
#include "team.h"

namespace vsssERUS{
	StatusJogo::Status StatusJogo::getStatusAtual(World* mundo){
		Ball ballPosition = *mundo->getBall();
		Team aliado = *mundo->getTeamPlayer();
		Team inimigo = *mundo->getEnemy();
		for(int i = 0; i < MAX_TEAM_SIZE; i++){
			if (inimigo.getPlayerByIdx(i).distancia(ballPosition) < 1){
				if((mundo->getCampo()->getLado == Campo::Lado::Direita && ballPosition.getPosicao().getX() > 150-37.5) || (mundo->getCampo()->getLado == Campo::Lado::Esquerda && ballPosition.getPosicao().getX() < 37.5))
					return Status::ataqueInimigo;
				return Status::posseInimiga;
			}
			if (aliado.getPlayerByIdx(i).distancia(ballPosition) < 1){
				if((mundo->getCampo()->getLado == Campo::Lado::Direita && ballPosition.getPosicao().getX() < 150-37.5) || (mundo->getCampo()->getLado == Campo::Lado::Esquerda && ballPosition.getPosicao().getX() > 37.5))
					return Status::ataqueAliado;
				return Status::posseAliada;
			}
		}
		return Status::bolaSolta;
	}

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
		for(int i = 0; i < 3; i++) this->jogadores->adicionaAoTime(*jogadores[i]);
	}

	Team* World::getTeamPlayer(){
		return this->jogadores;
	}

	void World::setEnemy(Enemy** inimigos){
		for(int i = 0; i < 3; i++) this->inimigos->adicionaAoTime(*inimigos[i]);
	}

	Team* World::getEnemy(){
		return this->inimigos;
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
}