#ifndef CAMPO_H
#define CAMPO_H

#include "teamplayer.h"
#include <cstdio>
#include <cstdlib>

class TeamPlayer;



class Campo
{
	/* Nome do módulo: Limite
	 * Ano de criação: 2018/10
	 * Descrição do módulo: Criação dos lados do campo
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
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    bool estaDentroDoCampo(Ponto posicao);

    /* campoPotencial
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    double campoPotencial(TeamPlayer jogador);

    /* atualizarCampo
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    void atualizarCampo(char* campo);

    /* getLado
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    Lado getLado(){
    	return this->nossoLado;
    }

    /* setLado
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    void setLado(int x);

    /* getBordaSuperior
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    int getBordaSuperior();

    /* getBordaInferior
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
	int getBordaInferior();

	/* getBordaEsquerda
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
	int getBordaEsquerda();

	/* getBordaDireita
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
	int getBordaDireita();

	/* getMeioDeCampo
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    Ponto getMeioDeCampo();

    /* getMeioDeGolAliado
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    Ponto getMeioDeGolAliado();

    /* getMeioDeGolInimigo
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    Ponto getMeioDeGolInimigo();

};

#endif // CAMPO_H
