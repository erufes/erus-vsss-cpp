#ifndef ENEMY_H_
#define ENEMY_H_
#include "player.h"

/* Nome do módulo: Enemy
 * Ano de criação: 2018/11
 * Descrição do módulo: Classe que representa jogadores inimigos no campo. Criado para prever suas posições.
 * 						Um jogador inimigo não é controlável pelo sistema pois deve ser contralado por sistemas de outros.
 * Versão: 1.1
 * Pré-requisitos posição antiga do inimigo e seu ângulo de 0 a 2pi
 * Membros: Ricardo Ramos
 */

class Enemy: public Player{
public:
	Enemy(int id = 0,float theta = 0.0);
	virtual ~Enemy();
	bool isEnemy(){
		return true;
	}
	std::pair<double, double> previsaoDePosicao(){
		return this->Player::previsaoDePosicao();
	}
};

#endif /* ENEMY_H_ */
