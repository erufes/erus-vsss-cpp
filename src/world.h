#ifndef WORLD_H_
#define WORLD_H_
#include "ball.h"
#include "enemy.h"
#include "campo.h"
#include "teamplayer.h"

/* Nome do módulo: World
 * Ano de criação: 2019/01
 * Descrição do módulo: Classe que representa o mundo, contendo cada componete que exite. Criado para facilitar armazenamento e passagem de parâmetros.
 * Versão: 1.0
 * Pré-requisitos componentes do mundo existentes
 * Membros: Ricardo Ramos
 */
class Ball;
class TeamPlayer;
class Campo;
class World {
	Ball* bola;
	TeamPlayer* jogadores[3];
	Enemy* inimigos[3];
	Campo* campo;
public:
	World(Campo* campo, TeamPlayer** jogadores, Enemy** inimigos, Ball* bola);
	virtual ~World();
	void setBall(Ball* bola);
	Ball* getBall();
	void setTeamPlayer(TeamPlayer** jogadores);
	TeamPlayer** getTeamPlayer();
	void setEnemy(Enemy** inimigos);
	Enemy** getEnemy();
	void setCampo(Campo* campo);
	Campo* getCampo();
};

#endif /* WORLD_H_ */
