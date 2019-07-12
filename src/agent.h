#ifndef AGENT_H
#define AGENT_H

/* Nome: Agente
 * Ano de criação: 2018/10
 * Descrição do módulo: Representa objetos no campo (bola, jogadores, etc..), clase abstrata que reune informações desses objeto e abstrai o tipo de objeto que se trata.
 * Versão: 1.1
 * testado!! Selo Valdino de Garantia \0/
 * Pré-requisitos: NULL
 * Membros: Ricardo Ramos, Gabriel Valdino
 */

#include "ponto.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace vsssERUS{
	class Agent
	{
		Ponto posicao;
		vector<Ponto> posicoesAnteriores;
	public:
		Agent(double x = 0, double y = 0);
		Agent(Ponto ponto);
		virtual ~Agent(){};

		/* getxyOld
		* Intenção da função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		vector<Ponto> getxyOld();

		/* previsaoDePosicao
		* Intenção da função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		virtual std::pair<double, double> previsaoDePosicao();

		/* updatePosition
		* Intenção da função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		void updatePosition(double x, double y);
		void updatePosition(Ponto ponto);

		/* getPonto
		* Intenção da função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Ponto getPonto();

		/* distancia
		* Intenção da função:
		* Pré-Requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		float distancia(Agent& agente);

	};
}
#endif // AGENT_H
