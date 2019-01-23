#ifndef ENEMY_H_
#define ENEMY_H_
#include "player.h"

	namespace vsssERUS{
	/* Nome do m�dulo: Enemy
	* Ano de cria��o: 2018/11
	* Descri��o do m�dulo: Classe que representa jogadores inimigos no campo. Criado para prever suas posi��es.
	* 						Um jogador inimigo n�o � control�vel pelo sistema pois deve ser contralado por sistemas de outros.
	* Vers�o: 1.1
	* Pr�-requisitos posi��o antiga do inimigo e seu �ngulo de 0 a 2pi
	* Membros: Ricardo Ramos
	*/

	class Enemy: public Player{
	public:
		Enemy(int id = 0,float theta = 0.0);
		virtual ~Enemy();

		/* isEnemy
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		bool isEnemy(){
			return true;
		}

		/* previsaoDePosicao
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		std::pair<double, double> previsaoDePosicao(){
			return this->Player::previsaoDePosicao();
		}
	};
}
#endif /* ENEMY_H_ */
