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

 /* Nome da função
  * Intenção da função:
  * Pré-requisitos:
  * Efeitos colaterais:
  * Parâmetros:
  * Retorno:
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

	  	/**
  		* Nome da função:       getxyOld;
  		* Intenção da função:   Retorna as posições anteriores;
  		* Pré-Requisitos:       Não há;
  		* Efeitos colaterais:   Não há;
  		* Parâmetros:           Não há;
  		* Retorno:						  (vector<Ponto>) posicoesAnteriores: localização anterior;
  		*/
		vector<Ponto> getxyOld() const;

		  /**
		  * Nome da função:       previsaoDePosicao;
		  * Intenção da função:   Faz a previsão de uma futura posição da bola/player;
		  * Pré-Requisitos:       Não há;
		  * Efeitos colaterais:   Não há;
		  * Parâmetros:           Não há;
		  * Retorno:						  pair<double, double> ponto_futuro: localização futura;
		  */
		virtual std::pair<double, double> previsaoDePosicao() const;

  		/**
  		* Nome da função:       updatePosition
  		* Intenção da função:   Atualização da posição do robô;
		  * Pré-Requisitos:       Não há;
		  * Efeitos colaterais:   Não há;
		  * Parâmetros:           ((double) x:posição, (double) y: posição) ou ((Ponto)ponto: vetor de posição);
		  * Retorno:						  void: são atualizados os vetores de posição por meio da função sem necessariamente precisar de um retorno;
		  */
		void updatePosition(double x, double y);
		void updatePosition(Ponto ponto);

		  /**
	  	* Nome da função:       getPosicao;
	  	* Intenção da função:   Função que chama a posição atual;
  		* Pré-Requisitos:       Não há;
	  	* Efeitos colaterais:   Não há;
	  	* Parâmetros:           Não há;
	  	* Retorno:						  (Ponto) posição: posição atual;
  		*/

		Ponto getPosicao() const;

  		/**
  		* Nome da função:       distancia;
  		* Intenção da função:   Função que chama a posição atual;
  		* Pré-Requisitos:       Não há;
  		* Efeitos colaterais:   Não há;
  		* Parâmetros:           Não há;
  		* Retorno:						  (Ponto) posição: posição atual;
  		*/

		float distancia(Agent& agente) const;
	};
}
#endif // AGENT_H
