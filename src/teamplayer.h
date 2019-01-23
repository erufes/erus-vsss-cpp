#define UsingSimulator

//.cpp incompleto
#ifndef TEAMPLAYER_H
#define TEAMPLAYER_H
#include "player.h"
#include "ataquebehavior.h"

#include "defesabehavior.h"
#include "goleirobehavior.h"

#ifdef UsingSimulator
#include <WheelsCommand.h>
#include "utils.hpp"
using namespace vss;
#endif

namespace vsssERUS{
	class Ponto;

	/* Nome do m�dulo: TeamPlayer
	* Ano de cria��o: 2018/12
	* Descri��o do m�dulo: Classe que representa jogadores do time, criado para definir as fun��es de cada rob� {Goleiro, Atacante, Defensor} e seus m�todos de controle.
	* Vers�o: 1.1
	* Pr�-requisitos: pr�-requisitos de player
	* Membros: Ricardo Ramos
	*/

	enum Funcao{Goleiro, Atacante, Defensor};
	class PlayBehavior;
	class TeamPlayer: public Player
	{
		PlayBehavior* comportamento;
		double distanciaMinDaParede;
	public:
		TeamPlayer(Funcao comportamento, int id = 0,double theta = 0.0, double distanciaMinDaParede = 0.0);

		/* movimenta
		* Inten��o da fun��o: Calcular onde o rob� dever� ir
		* Pr�-requisitos: Comportamento correto
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do rob�
		* Retorno: Posi��o para onde o rob� dever� se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Inten��o da fun��o: Calcular velocidade do rob� para ir at� a posi�ao desejada
		* Pr�-requisitos: Comportamento correto
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o para onde o rob� dever� ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/* mudaComortamento
		* Inten��o da fun��o: Mudar o comportamento do rob�, para goleiro, atacante ou defensor
		* Pr�-requisitos: Nova fun��o v�lida {Goleiro, Atacante, Defensor}
		* Efeitos colaterais: Muda a funcionalidade das fun��es movimenta() e controle()
		* Parametros: Funcao nova para o rob�
		* Retorno: N�o possui retorno
		*/
		void mudaComportamento(Funcao novo);

		/* previsaoDePosicao
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		std::pair<double,double> previsaoDePosicao(){
			return this->Player::previsaoDePosicao();
		};

		/* isEnemy
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		bool isEnemy(){
			return false;
		};

	#ifdef UsingSimulator

		vss::WheelsCommand update(vss::State state, int index) {
			Utils::Posture objective = defineObjective(state, index);
			return motionControl(state, objective, index);
		}

		Utils::Posture defineObjective(vss::State, int index)
		{
			// Retorne o objetivo aqui
			return Utils::Posture(10., 65.0, M_PI/4.);
		}

		vss::WheelsCommand motionControl(vss::State state, Utils::Posture objective, int index);

	#endif

	};
}
#endif // TEAMPLAYER_H
