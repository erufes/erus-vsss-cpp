#ifndef WORLD_H_
#define WORLD_H_
/* Nome do módulo :      World
 * Ano de criação :      2019/01
 * Descrição do módulo : Classe que representa o mundo, contendo cada componete que existe. Criado para facilitar armazenamento e passagem de parâmetros.
 * Versão :              1.0
 * Pré-requisitos :      Ball
 *                       Enemy
 *                       Campo
 *                       TeamPlayer
 *                       Notifier
 *                       String
 * Membros :             Ricardo Ramos
 */

#include "ball.h"
#include "enemy.h"
#include "campo.h"
#include "teamplayer.h"
#include "notifier.h"
#include "string"

namespace vsssERUS{
	
	class Ball;
	class TeamPlayer;
	class Campo;
	class World {
		Ball* bola;
		TeamPlayer* jogadores[MAX_TEAM_SIZE];
		Enemy* inimigos[MAX_TEAM_SIZE];
		Campo* campo;
		Notifier atualizacaoCampo; 	//Notificador de atualização de posições
	public:

		World(Campo* campo, TeamPlayer** jogadores, Enemy** inimigos, Ball* bola);

		virtual ~World();

        /* Nome da função :     setBall
         * Intenção da função : Mudar a referência de bola
         * Pré-requisitos :     Nova bola alocada em memória
         * Efeitos colaterais : A referência de bola é alterada
         * Parâmetros :         Ball* : nova referência de bola
         * Retorno :            Nenhum
         */
		void setBall(Ball* bola);

        /* Nome da função :     getBall
         * Intenção da função : Recuperar a referência de bola
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            Ball* : referência de bola
         */
		Ball* getBall();

        /* Nome da função :     setTeamPlayer
         * Intenção da função : Mudar a referência de time aliado
         * Pré-requisitos :     Time alocado em memória
         * Efeitos colaterais : A referência de time é alterada
         * Parâmetros :         TeamPlayer** : nova referência de time de aliados
         * Retorno :            Nenhum
         */
		void setTeamPlayer(TeamPlayer** jogadores);

        /* Nome da função :     getTeamPlayer
         * Intenção da função : Recuperar a referência de time
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            TeamPlayer** : referência de time de aliados
         */
		TeamPlayer** getTeamPlayer();

        /* Nome da função :     setEnemy
         * Intenção da função : Mudar a referência de time imigido
         * Pré-requisitos :     Time alocado em memória
         * Efeitos colaterais : A referência de time é alterada
         * Parâmetros :         Enemy** : nova referência de time de imigidos
         * Retorno :            Nenhum
         */
		void setEnemy(Enemy** inimigos);

        /* Nome da função :     getEnemy
         * Intenção da função : Recuperar a referência de time
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            Enemy** : referência de time de inimigos
         */
		Enemy** getEnemy();

        /* Nome da função :     setCampo
         * Intenção da função : Alterar a referência de campo
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : A referência de campo é alterada
         * Parâmetros :         Campo* : referência de campo
         * Retorno :            Nenhum
         */
		void setCampo(Campo* campo);

        /* Nome da função :     getCampo
         * Intenção da função : Recuperar a referência de campo
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            Campo* : referência de campo
         */
		Campo* getCampo();

        /* Nome da função :     forceNotify
         * Intenção da função : Forçar notificação de evento
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Todos os observers de World são notificados
         * Parâmetros :         string : mensagem de notificação 
         * Retorno :            Nenhum
         */
		void forceNotify(string s);
	};
}
#endif /* WORLD_H_ */
