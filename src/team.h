#ifndef TEAM_H
#define TEAM_H

/* Nome do módulo :         Time
 * Ano de criação :         2019/07
 * Descrição do módulo :    Representa os times do jogo.
 * Versão :                 1.0
 * Pré-requisitos :         Player
 *                          vector (biblioteca padrão)
 *                          cstdlib (biblioteca padrão)
 *                          iostream (biblioteca padrão)
 */
#include <vector>
#include <cstdlib>
#include <iostream>

#include "player.h"
#define MAX_TEAM_SIZE 3


using namespace std;
namespace vsssERUS{
	class Team
	{
		vector<Player*> jogadores;
		
	public:
        enum cor {
			INDEFINIDA,
			Amarelo,
			Azul,
			Verde,
			Rosa
		};
		Team();
		virtual ~Team();

        /* Nome da função :     adicionaAoTime
         * Intenção da função : Adiconar novo jogador ao time
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : O jogador entra na lista de jogadores do time
         * Parâmetros :         Player : jogador a ser inserido
         * Retorno :            Nenhum
         */
		void adicionaAoTime(Player& p);

        /* Nome da função :     getPlayerByIdx
         * Intenção da função : Retorna o jogador na posição desejada na lista de jogadores
         * Pré-requisitos :     Indice entre 0 e 2
         * Efeitos colaterais : Nenhum
         * Parâmetros :         int : Indice do jogador na lista
         * Retorno :            Player : jogador na posição pedida
         */
		Player& getPlayerByIdx(int idx) { return *this->jogadores[idx]; }
	};
}
#endif // TEAM_H
