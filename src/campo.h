#ifndef CAMPO_H
#define CAMPO_H

#include "teamplayer.h"
#include <cstdio>
#include <cstdlib>

class TeamPlayer;


namespace vsssERUS{
	class Campo
	{
		/* Nome do m�dulo: Limite
		* Ano de cria��o: 2018/10
		* Descri��o do m�dulo: Cria��o dos lados do campo
		* Vers�o: 1.1
		* tstado!! Selo Valdino de Garantia \0/
		* Pr�-requisitos: Pontos distintos
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

		enum Lado{Esquerdo, Direito};

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
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		bool estaDentroDoCampo(Ponto posicao);

		/* campoPotencial
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		double campoPotencial(TeamPlayer jogador);

		/* atualizarCampo
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		void atualizarCampo(char* campo);

		/* getLado
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		Lado getLado(){
			return this->nossoLado;
		}

		/* setLado
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		void setLado(int x);

		/* getBordaSuperior
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		int getBordaSuperior();

		/* getBordaInferior
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		int getBordaInferior();

		/* getBordaEsquerda
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		int getBordaEsquerda();

		/* getBordaDireita
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		int getBordaDireita();

		/* getMeioDeCampo
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		Ponto getMeioDeCampo();

		/* getMeioDeGolAliado
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		Ponto getMeioDeGolAliado();

		/* getMeioDeGolInimigo
		* Inten��o da fun��o:
		* Pr�-requisitos:
		* Efeitos colaterais:
		* Parametros:
		* Retorno:
		*/
		Ponto getMeioDeGolInimigo();

	};
}
#endif // CAMPO_H
