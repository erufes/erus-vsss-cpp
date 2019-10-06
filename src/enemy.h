#ifndef ENEMY_H_
#define ENEMY_H_

/* Nome do módulo :         Enemy
 * Ano de criação :         2018/11
 * Descrição do módulo :    Classe que representa jogadores inimigos no campo. Criado para prever suas posições.
 * 						    Um jogador inimigo não é controlável pelo sistema, pois deve ser controlado por sistemas de outros.
 * Versão :                 1.1
 * Pré-requisitos :         Player
 * Membros  :               Ricardo Ramos
 */


#include "player.h"

namespace vsssERUS{
	class Enemy: public Player{
	public:
		Enemy(int id = 0,float theta = 0.0);
		virtual ~Enemy();

		/* Nome da Função :     isEnemy
		 * Intenção da Função : Saber se o jogador é instância de Enemy (caso de polimorfismo)
		 * Pré-requisitos :     Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros :         Nenhum
		 * Retorno :            bool : Sempre true
		 */
		bool isEnemy(){
			return true;
		}
	};
}
#endif /* ENEMY_H_ */
