#ifndef CAMPO_H
#define CAMPO_H

#include <cstdio>
#include <cstdlib>
#include "teamplayer.h"

class TeamPlayer;

// TODO: Atualizar as informações abaixo
/* Nome do módulo: Limite
		* Ano de criação: 2018/10
		* Descrição do módulo: Informações sobre os limites do campo
		* Versão: 1.1
		* tstado!! Selo Valdino de Garantia \0/
		* Pré-requisitos: Pontos distintos
		* Membros: Ricardo Ramos, Gabriel Valdino
*/

namespace vsssERUS{
	class Campo
	{
		/* Nome do módulo: Limite
		* Ano de criação: 2018/10
		* Descrição do módulo: Informações sobre os limites do campo
		* Versão: 1.1
		* tstado!! Selo Valdino de Garantia \0/
		* Pré-requisitos: Pontos distintos
		* Membros: Ricardo Ramos, Gabriel Valdino
		*/

		class Limite
		{
			Ponto ponto1;
			Ponto ponto2;
		public:
			Limite(Ponto p1 = Ponto(0,0), Ponto p2 = Ponto(0,0));
			Ponto pontoMedio();
			double distancia();
			double distanciaParaOutroLimite(Limite outro);
			Ponto returnPonto(int x);
		};

		enum Lado {
			Esquerdo,
			Direito
			};

		Limite limiteSuperior;
		Limite limiteInferior;
		Limite golDireito;
		Limite golEsquerdo;
		Limite limiteDireito;
		Limite limiteEsquerdo;
		Lado nossoLado;

	public:
		Campo(char* campo);

		/* estaDentroDoCampo
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		bool estaDentroDoCampo(Ponto posicao);

		/* campoPotencial
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		double campoPotencial(TeamPlayer jogador);

		/* atualizarCampo
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		void atualizarCampo(char* campo);

		/* getLado
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Lado getLado(){
			return this->nossoLado;
		}

		/* setLado
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		void setLado(int x);

		/* getBordaSuperior
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		int getBordaSuperior();

		/* getBordaInferior
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		int getBordaInferior();

		/* getBordaEsquerda
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		int getBordaEsquerda();

		/* getBordaDireita
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		int getBordaDireita();

		/* getMeioDeCampo
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Ponto getMeioDeCampo();

		/* getMeioDeGolAliado
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Ponto getMeioDeGolAliado();

		/* getMeioDeGolInimigo
		* Intenção da Função:
		* Pré-requisitos:
		* Efeitos colaterais:
		* Parâmetros:
		* Retorno:
		*/
		Ponto getMeioDeGolInimigo();

	};
}

#endif // CAMPO_H
