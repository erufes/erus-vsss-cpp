#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H

#define UsingSimulator

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include <Communications/CommandSender.h>
#endif

#include "player.h"
#include "ataquebehavior.h"
#include "defesabehavior.h"
#include "goleirobehavior.h"
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

/*
 * Nome do módulo: TeamPlayer
 * Ano de criação: 2018/12
 * Descrição do módulo: Classe que representa jogadores do time, criado para definir as funções de cada robô {Goleiro, Atacante, Defensor} e seus métodos de controle.
 * Versão: 1.1
 * Pré-requisitos: pré-requisitos de player
 * Membros: Ricardo Ramos
 */
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
		void adicionaPontoDeRepulsao(Ponto p);
		void adicionaPontoDeRepulsao(Ponto p, double i);
		void adicionaPontoDeAtracao(Ponto p);
		void adicionaPontoDeAtracao(Ponto p, double i);
	public:
		void setCampo(Campo& c) { this->campo = &c; }
		void notifica();
		TeamPlayer(Funcao comportamento, int id = 0,double theta = 0.0, double distanciaMinDaParede = 0.0);

		/*
		 * Nome da função:       movimenta;
		 * Intenção da Função:   Calcular onde o robô deverá ir;
		 * Pré-Requisitos:       O robô deve possuir uma posição inicial válida;
		 * Efeitos colaterais:   Não há;
		 * Parametros:           (Ponto) posição: Posição alvo do robô;
		 *                       (World) mundo: Informações sobre o estado do jogo;
		 * Retorno:              (Ponto) comportamento: Posição para onde o robô deverá se movimentar;
		 */
		Ponto movimenta(Ponto posicao, World* mundo);

		/*
		 * Nome da função:       controle;
		 * Intenção da Função:   Controlar o robô para ele ir até determinada posição;
		 * Pré-Requisitos:       O robô deve possuir uma posição inicial válida;
		 * Efeitos colaterais:   Não possui efeitos colaterais;
		 * Parametros:           (Ponto) posição: Posição alvo do robô;
		 *                       (World) mundo: Informações sobre o estado do jogo;
		 * Retorno:              (pair<int, int>) velocidades: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		 */
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/*
		 * Nome da função:       mudaComportamento;
		 * Intenção da Função:   Mudar o comportamento do robô para goleiro, atacante ou defensor;
		 * Pré-Requisitos:       Não há;
		 * Efeitos colaterais:   Altera o comportamento das funções movimenta() e controle();
		 * Parametros:           (Funcao) novo: Função nova para o robô;
		 * Retorno:              Não possui retorno;
		 */
		void mudaComportamento(Funcao novo);

		bool isEnemy(){
			return false;
		};

	#ifdef UsingSimulator
		vss::WheelsCommand update(vss::State state, int index, vsssERUS::World* mundo);

		Utils::Posture defineObjective(vss::State, int index, vsssERUS::World* mundo);

		vss::WheelsCommand motionControl(vss::State state, Utils::Posture objective, int index);

	#endif

	};
}
#endif // TEAMPLAYER_H
