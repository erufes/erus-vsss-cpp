#ifndef ENEMY_H
#define ENEMY_H
#include "player.h"

namespace vsssERUS{
/* Nome do módulo: Enemy
* Ano de criação: 2018/11
* Descrição do módulo: Classe que representa jogadores inimigos no campo. Criado para prever suas posições.
* 						Um jogador inimigo não é controlável pelo sistema, pois deve ser controlado por sistemas de outros.
* Versão: 1.1
* Pré-requisitos: posição antiga do inimigo e seu ângulo, de 0 a 2pi
* Membros: Ricardo Ramos
*/

class Enemy: public Player{
public:
	Enemy(int id = 0,float theta = 0.0);
	virtual ~Enemy();

	/* isEnemy
	* Intenção da Função:
	* Pré-requisitos:
	* Efeitos colaterais:
	* Parâmetros:
	* Retorno:
	*/
	bool isEnemy(){
		return true;
	}
};
} // vsssERUS
#endif // ENEMY_H
