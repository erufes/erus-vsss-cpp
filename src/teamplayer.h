#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H

/* Nome do módulo:      TeamPlayer
 * Ano de criação:      2018/12
 * Descrição do módulo: Classe que representa jogadores do time, criado para definir as funções de cada robô {Goleiro, Atacante, Defensor} e seus métodos de controle.
 * Versão:              1.2
 * Pré-requisitos:      Player
 *                      PlayBehaviour
 *                      Utils
 *                      Observer
 * Membros:             Gabriel Pietroluongo
 *                      Ricardo Ramos
 */

#define UsingSimulator

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include <Communications/CommandSender.h>
#endif

#include "player.h"
#include "playbehavior.h"
#include "utils.h"
#include "observer.h"

// Constantes de discretização do campo

#define STEP_X 7.5
#define STEP_Y 7.5
#define VSSIZE_X 7.5
#define VSSIZE_Y 7.5
#define VSSIZE_Z 7.5

#define DISC_X 20
#define DISC_Y 17


namespace vsssERUS{

	class Campo;

	enum Funcao {
		Goleiro,
		Atacante,
		Defensor
	};

	class TeamPlayer: public Player, public Observer 
	{
		PlayBehavior* comportamento;
		double distanciaMinDaParede;
		double campoPotencial[DISC_X][DISC_Y];
		void atualizaCampoPotencial();
		Campo* campo;
	public:
		TeamPlayer(Funcao comportamento, int id = 0,double theta = 0.0, double distanciaMinDaParede = 0.0);

        /* Nome da função :     setCampo
         * Intenção da função : Alterar o campo do jogo
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : A referência de campo é alterada
         * Parâmetros :         Campo : novo campo
         * Retorno :            Nenhum
         */
		void setCampo(Campo& c) { this->campo = &c; }

        /* Nome da função :     notifica
         * Intenção da função : Implementar padrão Observer
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Calculo de campos potenciais
         * Parâmetros :         Nenhum
         * Retorno :            Nenhum
         */
		void notifica();

		/* Nome da função:       movimenta
		 * Intenção da Função:   Calcular onde o robô deverá ir
		 * Pré-Requisitos:       O robô deve possuir uma posição inicial válida
		 * Efeitos colaterais:   Nenhum
		 * Parametros:           Ponto : Posição alvo do robô
		 *                       World : Mundo com informações sobre o estado do jogo
		 * Retorno:              Ponto : Posição para onde o robô deverá se movimentar
		 */
		Ponto movimenta(Ponto posicao, World* mundo);

		/* Nome da função:       controle
		 * Intenção da Função:   Controlar o robô para ele ir até determinada posição
		 * Pré-Requisitos:       O robô deve possuir uma posição inicial válida
		 * Efeitos colaterais:   Não possui efeitos colaterais
		 * Parametros:           Ponto : Posição alvo do robô
		 *                       World : Mundo com informações sobre o estado do jogo
		 * Retorno:              pair<int, int> Velocidades das rodas, primeiro a direira e segundo a esquerda
		 */
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/* Nome da função:       mudaComportamento
		 * Intenção da Função:   Mudar o comportamento do robô para goleiro, atacante ou defensor
		 * Pré-Requisitos:       Nenhum
		 * Efeitos colaterais:   Altera o comportamento das funções movimenta() e controle()
		 * Parametros:           Funcao : Função nova para o robô
		 * Retorno:              Nenhum
		 */
		void mudaComportamento(Funcao novo);

        /* Nome da Função :     isEnemy
		 * Intenção da Função : Saber se o jogador é instância de Enemy (caso de polimorfismo)
		 * Pré-requisitos :     Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros :         Nenhum
		 * Retorno :            bool : Sempre false
		 */
		bool isEnemy(){
			return false;
		};

	#ifdef UsingSimulator
        /* Nome da função:       update
		 * Intenção da Função:   Controlar o robô para ele ir até determinada posição
		 * Pré-Requisitos:       Simulador
		 * Efeitos colaterais:   Não possui efeitos colaterais
		 * Parametros:           State : Estado de jogo
         *                       int :   Indice do jogador
		 *                       World : Mundo com informações sobre o estado do jogo
		 * Retorno:              vss::WheelsCommand : Velocidades das rodas, primeiro a direira e segundo a esquerda
		 */
		vss::WheelsCommand update(vss::State state, int index, vsssERUS::World* mundo);

        /* Nome da função:       defineObjective
		 * Intenção da Função:   Calcular onde o robô deverá ir
		 * Pré-Requisitos:       O robô deve possuir uma posição inicial válida
		 * Efeitos colaterais:   Nenhum
		 * Parametros:           State : Estado de jogo
         *                       int :   Indice do jogador
		 *                       World : Mundo com informações sobre o estado do jogo
		 * Retorno:              Utils::Posture : Posição para onde o robô deverá se movimentar e angulo de movimentação
		 */
		Utils::Posture defineObjective(vss::State, int index, vsssERUS::World* mundo);

        /* Nome da função :     motionControl
         * Intenção da função : Algoritmo de Movimentação do Simulador
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         State : Estado de jogo
         *                      Utils::Posture : Posição para onde o robô deverá se movimentar e angulo de movimentação
		 *                      int :   Indice do jogador
         * Retorno:             vss::WheelsCommand : Velocidades das rodas, primeiro a direira e segundo a esquerda
         */
		vss::WheelsCommand motionControl(vss::State state, Utils::Posture objective, int index);

	#endif

	};
}
#endif // TEAMPLAYER_H
