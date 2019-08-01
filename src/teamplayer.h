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

/* Nome do módulo: TeamPlayer
* Ano de criação: 2018/12
* Descrição do módulo: Classe que representa jogadores do time, criado para definir as funções de cada robô {Goleiro, Atacante, Defensor} e seus métodos de controle.
* Versão: 1.1
* Pré-requisitos: pré-requisitos de player
* Membros: Ricardo Ramos
*/

namespace vsssERUS{

	enum Funcao {
		Goleiro,
		Atacante,
		Defensor
	};

	class TeamPlayer: public Player
	{
		PlayBehavior* comportamento;
		double distanciaMinDaParede;
	public:
		TeamPlayer(Funcao comportamento, int id = 0,double theta = 0.0, double distanciaMinDaParede = 0.0);

		/**
		* Nome da função:       movimenta;
		* Intenção da Função:   Calcular onde o robô deverá ir;
		* Pré-Requisitos:       Comportamento correto;
		* Efeitos colaterais:   Não possui efeitos colaterais;
		* Parametros:           (Ponto) posição: posição do robô;
		*                       (World) mundo: posição do robô;
		* Retorno:              (PlayBehavior*) comportamento: Posição para onde o robô deverá se movimentar;
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/**
		* Nome da função:       controle;
		* Intenção da Função:   Calcular velocidade do robô para ir até a posição desejada;
		* Pré-Requisitos:       Comportamento correto;
		* Efeitos colaterais:   Não possui efeitos colaterais;
		* Parametros:           (Ponto) posição: posição do robô;
		*                       (World) mundo: posição do robô;
		* Retorno:              (PlayBehavior*) comportamento: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/**
		* Nome da função:       mudaComportamento;
		* Intenção da Função:   Mudar o comportamento do robô, para goleiro, atacante ou defensor;
		* Pré-Requisitos:       Nova função válida {Goleiro, Atacante, Defensor};
		* Efeitos colaterais:   Muda a funcionalidade das funções movimenta() e controle();
		* Parametros:           (Funcao) novo: Funcao nova para o robô;
		* Retorno:              Não possui retorno;
		*/
		void mudaComportamento(Funcao novo);

		/**
		* Nome da função:       isEnemy
		* Intenção da Função:   Identificar inimigos;
		* Pré-Requisitos:       Não há;
		* Efeitos colaterais:   Não há;
		* Parametros:           Não há;
		* Retorno:              (bool) false: indentificação de adversarios;
		*/
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
