#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H

#define UsingSimulator

#include "player.h"
#include "ataquebehavior.h"
#include "defesabehavior.h"
#include "goleirobehavior.h"

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include <Communications/CommandSender.h>
namespace Utils{ class Posture;};
#endif

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

		/* movimenta
		* Intenção da Função: Calcular onde o robô deverá ir
		* Pré-Requisitos: Comportamento correto
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Intenção da Função: Calcular velocidade do robô para ir at� a posi�ao desejada
		* Pré-Requisitos: Comportamento correto
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posição para onde o robô deverá ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/* mudaComortamento
		* Intenção da Função: Mudar o comportamento do robô, para goleiro, atacante ou defensor
		* Pré-Requisitos: Nova função válida {Goleiro, Atacante, Defensor}
		* Efeitos colaterais: Muda a funcionalidade das funções movimenta() e controle()
		* Parametros: Funcao nova para o robô
		* Retorno: Não possui retorno
		*/
		void mudaComportamento(Funcao novo);

		/* previsaoDePosicao
		* Intenção da Função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		std::pair<double,double> previsaoDePosicao(){
			return this->Player::previsaoDePosicao();
		};

		/* isEnemy
		* Intenção da Função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
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
