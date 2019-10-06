#ifndef CAMPO_H
#define CAMPO_H

/* Nome do módulo: 		Campo
 * Ano de criação: 		2018/10
 * Descrição do módulo: Modulo que descreve o campo de jogo
 * Versão: 				1.2
 * Pré-requisitos: 		Team
 * 						TeamPlayer
 * 						Ball
 * 						cstdio (biblioteca padrão)
 * 						cstdlib (biblioteca padrão)
 * Membros: 			Gabriel Valdino
 * 						Lorena Bassani
 * 						Ricardo Ramos
 */

#include <cstdio>
#include <cstdlib>
#include "teamplayer.h"
#include "team.h"
#include "ball.h"

class TeamPlayer;

namespace vsssERUS {

	class Campo {
		
	public:
		/* Nome do módulo : 	 Campo::Lado
		 * Ano de criação : 	 2018/10
		 * Descrição do módulo : Enumeração de lado entre "Esquerda" e "Direita"	
		 * Versão :				 1.0
		 * Pré-requisitos : 	 Vide Requisitos da classe Pai
		 * Membros :			 Lorena Bassani
		 */
		enum Lado {
			Esquerda,
			Direita
		};
	
		/* Nome do módulo :		 Limite
		 * Ano de criação : 	 2018/10
		 * Descrição do módulo : Informações sobre os limites do campo
		 * Versão : 			 1.1
		 * Pré-requisitos : 	 Vide Requisitos da classe Pai
		 * Membros: 			 Gabriel Valdino
		 *						 Ricardo Ramos
		 */
		class Limite {
			Ponto ponto1;
			Ponto ponto2;
		public:
			Limite(Ponto p1 = Ponto(0,0), Ponto p2 = Ponto(0,0));
			/* Nome da função : 	pontoMedio
			 * Intenção da função:	Calcular o ponto médio da reta limite
			 * Pré-requisitos:		Nenhum
			 * Efeitos colaterais:	Nenhum
			 * Parâmetros:			Nenhum
			 * Retorno:				Ponto : ponto médio da reta limite
			 */
			Ponto pontoMedio();

			/* Nome da função : 	distancia
			 * Intenção da função : determina a distância entre os pontos do limite
			 * Pré-requisitos :		Nenhum
			 * Efeitos colaterais :	Nenhum
			 * Parâmetros :			Nenhum
			 * Retorno :			double : distância entre os pontos do limite
			 */
			double distancia();

			/* Nome da função :		distanciaParaOutroLimite
			 * Intenção da função :	calcular a distância entre dois limites
			 * Pré-requisitos :		Limite de entrada não nulo
			 * Efeitos colaterais :	Nenhum
			 * Parâmetros :			Limite : limite para o qual quer definir a distância
			 * Retorno :			double : distância entre limites
			 */
			double distanciaParaOutroLimite(Limite outro);

			/* Nome da função :		returnPonto
			 * Intenção da função :	Retorna um dos pontos do limite
			 * Pré-requisitos :		Nenhum
			 * Efeitos colaterais :	Nenhum
			 * Parâmetros :			int : 1 para primeiro ponto, outros valores para o segundo ponto
			 * Retorno :			Ponto : ponto de acordo com a entrada
			 */
			Ponto returnPonto(int x);
		};

	private:
		Limite limiteSuperior;
		Limite limiteInferior;
		Limite golDireito;
		Limite golEsquerdo;
		Limite limiteDireito;
		Limite limiteEsquerdo;
		Lado nossoLado;

		Team* friendlies;
		Team* enemies;

		Ball* ball;

	public:
		Campo(char* campo);

		// Struct auxiliar para transmitir os dados posicionais para os teamPlayers
		struct dadosDoCampo {
			Ponto f1, f2, f3, e1, e2, e3, b;
		};

		/* Nome da Função : 	getPositions
		 * Intenção da Função: 	recebe posições dos teamPlayers
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			Nenhum
		 * Retorno: 			dadosDoCampo : posições dos teamPlayers
		 */
		dadosDoCampo& getPositions();

		/* Nome da Função : 	setBall
		 * Intenção da Função: 	alterar a referência da bola
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	altera a referência da bola do campo
		 * Parâmetros: 			Ball : nova referência de bola
		 * Retorno: 			Nenhum
		 */
		void setBall(Ball& b) { this->ball = &b; }

		/* Nome da Função : 	estaDentroDoCampo
		 * Intenção da Função: 	Dizer se uma dada posição pertence ao campo
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			Ponto : ponto a ser analisado
		 * Retorno: 			bool : True se está no campo, false caso contrario
		 */
		bool estaDentroDoCampo(Ponto posicao);

		/* Nome da Função : 	campoPotencial
		 * Intenção da Função: 	Calcular o campo potencial dado um jogador
		 * Pré-requisitos: 		Jogador válido e dentro de campo
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			TeamPlayer : O Jogador de referência para calcular o campo potêncial
		 * Retorno: 			double : (TODO : descobrir porque double)
		 */
		double campoPotencial(TeamPlayer jogador);

		/* Nome da Função :		atualizarCampo
		 * Intenção da Função: 	Atualizar o campo com novo arquivo
		 * Pré-requisitos: 		Nome de arquivo válido
		 * Efeitos colaterais:  Abre e lê um arquivo, depois fecha.
		 * 						Muda as configurações de limites do campo.
		 * Parâmetros: 			char* : Nome do arquivo a ser lido
		 * Retorno: 			Nenhum
		 */
		void atualizarCampo(char* campo);

		/* Nome da Função : 	getLado
		 * Intenção da Função: 	Retornar o lado defendido
		 * Pré-requisitos: 		Ter um lado defendido já configurado
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			Nenhum
		 * Retorno: 			Campo::Lado : Esquerda caso defende-se a esquerda, Direita caso contrario
		 */
		Lado getLado(){
			return this->nossoLado;
		}

		/* Nome da Função : 	setLado
		 * Intenção da Função: 	Dizer o lado que o time defende
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Muda o lado de defesa e ataque
		 * Parâmetros: 			int : 1 para esquerda, 2 para direita 
		 * Retorno: 			Nenhum
		 */
		void setLado(int x);

		/* Nome da Função : 	setLado
		 * Intenção da Função: 	Dizer o lado que o time defende
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Muda o lado de defesa e ataque
		 * Parâmetros: 			Campo::Lado : Esquerda caso defende-se a esquerda, Direita caso contrario 
		 * Retorno: 			Nenhum
		 */
		void setLado(Lado l){
			this->nossoLado = l;
		}

		/* Nome da Função : 	getBordaSuperior
		 * Intenção da Função :	Retornar a altura da borda superior
		 * Pré-requisitos :		Nenhum
		 * Efeitos colaterais :	Nenhum
		 * Parâmetros :			Nenhum
		 * Retorno :			float : altura da borda superior
		 */
		float getBordaSuperior();

		/* Nome da Função : 	getBordaInferior
		 * Intenção da Função :	Retornar a altura da borda inferior
		 * Pré-requisitos :		Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros :			Nenhum
		 * Retorno :			float : altura da borda inferior
		 */
		float getBordaInferior();

		/* Nome da Função : 	getBordaEsquerda
		 * Intenção da Função :	Retornar a posição da borda esquerda
		 * Pré-requisitos :		Nenhum
		 * Efeitos colaterais :	Nenhum
		 * Parâmetros :			Nenhum
		 * Retorno :			float : posição da borda esquerda
		 */
		float getBordaEsquerda();

		/* Nome da Função : 	getBordaDireita
		 * Intenção da Função :	Retornar a posição da borda direita
		 * Pré-requisitos :		Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros :			Nenhum
		 * Retorno :			float : posição da borda direita
		 */
		float getBordaDireita();

		/* Nome da Função : 	getMeioDeCampo
		 * Intenção da Função : Retorna o ponto do meio do campo
		 * Pré-requisitos : 	Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros : 		Nenhum
		 * Retorno : 			Ponto : ponto do meio do campo
		 */
		Ponto getMeioDeCampo();

		/* Nome da Função : 	getMeioDeGolAliado
		 * Intenção da Função : Retornar o ponto médio do gol aliado
		 * Pré-requisitos : 	Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros : 		Nenhum
		 * Retorno : 			Ponto : ponto do meio do gol aliado
		 */
		Ponto getMeioDeGolAliado();

		/* Nome da Função : 	getGolAliado
		 * Intenção da Função: 	Retornar o gol aliado
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			Nenhum
		 * Retorno: 			pair<Ponto, Ponto> : pontos de limite do gol aliado
		 */
		pair<Ponto, Ponto> getGolAliado();

		/* Nome da Função : 	getMeioDeGolInimigo
		 * Intenção da Função: 	Retornar o ponto médio do gol inimigo
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parâmetros: 			Nenhum
		 * Retorno: 			Ponto : ponto do meio do gol inimigo
		 */
		Ponto getMeioDeGolInimigo();

		/* Nome da Função : 	getGolInimigo
		 * Intenção da Função : Retornar o gol aliado
		 * Pré-requisitos : 	Nenhum
		 * Efeitos colaterais : Nenhum
		 * Parâmetros : 		Nenhum
		 * Retorno : 			pair<Ponto, Ponto> : pontos de limite do gol inimigo
		 */
		pair<Ponto, Ponto> getGolInimigo();

	};
}

#endif // CAMPO_H
