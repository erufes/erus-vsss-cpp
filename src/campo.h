#ifndef CAMPO_H
#define CAMPO_H

#include <cstdio>
#include <cstdlib>
#include "teamplayer.h"
#include "team.h"
#include "ball.h"
#include <cstdlib>

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
	private:
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
			Esquerda,
			Direita
			};

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
		// Struct auxiliar para transmitir os dados posicionais para os teamPlayers
		struct dadosDoCampo {
			Ponto f1, f2, f3, e1, e2, e3, b;
		};

		dadosDoCampo& getPositions();
		Campo(char* campo);

		/* estaDentroDoCampo
		 * Intenção da Função: Dizer se uma dada posição pertence ao campo
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Ponto a ser analisado
		 * Retorno: bool
		 */
		bool estaDentroDoCampo(Ponto posicao);

		/* campoPotencial
		* Intenção da Função: Calcular o campo potencial dado um jogador
		* Pré-requisitos: Jogador válido e dentro de campo
		* Efeitos colaterais: Nenhum
		* Parâmetros: O Jogador
		* Retorno: double
		*/
		double campoPotencial(TeamPlayer jogador);

		/* atualizarCampo
		 * Intenção da Função: Atualizar o campo com novo arquivo
		 * Pré-requisitos: Nome de arquivo válido
		 * Efeitos colaterais:  Abre e lê um arquivo, depois fecha.
		 * 						Muda as configurações de limites do campo.
		 * Parâmetros: Nome do arquivo a ser lido
		 * Retorno: Nenhum
		 */
		void atualizarCampo(char* campo);

		/* getLado
		 * Intenção da Função: Retornar o lado defendido
		 * Pré-requisitos: Ter um lado defendido já configurado
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Lado
		 */
		Lado getLado(){
			return this->nossoLado;
		}

		/* setLado
		 * Intenção da Função: Dizer o lado que o time defende
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Muda o lado de defesa e ataque
		 * Parâmetros: inteiro 1 para esquerda, 2 para direita 
		 * Retorno: Nenhum
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
		 * Intenção da Função: Retorna o ponto do meio do campo
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Ponto
		 */
		Ponto getMeioDeCampo();

		/* getMeioDeGolAliado
		 * Intenção da Função: Retornar o ponto médio do gol aliado
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Ponto
		 */
		Ponto getMeioDeGolAliado();

		/* getGolAliado
		 * Intenção da Função: Retornar o gol aliado
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Par de Pontos
		 */
		pair<Ponto, Ponto> getGolAliado();

		/* getMeioDeGolInimigo
		 * Intenção da Função: Retornar o ponto médio do gol inimigo
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Ponto
		 */
		Ponto getMeioDeGolInimigo();

		/* Método getGolInimigo
		 * Intenção da Função: Retornar o gol aliado
		 * Pré-requisitos: Nenhum
		 * Efeitos colaterais: Nenhum
		 * Parâmetros: Nenhum
		 * Retorno: Par de Pontos
		 */
		pair<Ponto, Ponto> getGolInimigo();

		void setBall(Ball& b) { this->ball = &b; }

	};
}

#endif // CAMPO_H
