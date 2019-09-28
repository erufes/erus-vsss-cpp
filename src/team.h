#ifndef TEAM_H
#define TEAM_H

/* Nome: Time
 * Ano de criação: 2019/07
 * Descrição do módulo: Representa os times do jogo.
 * Versão: 1.0
 * Pré-requisitos: NULL
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
		enum cor {
			INDEFINIDA,
			Amarelo,
			Azul,
			Verde,
			Rosa
		};
	public:
		Team();
		virtual ~Team();
		void adicionaAoTime(Player& p);
		Player& getPlayerByIdx(int idx) { return *this->jogadores[idx]; }
	};
}
#endif // TEAM_H
