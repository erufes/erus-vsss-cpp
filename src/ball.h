#ifndef BALL_H
#define BALL_H

/* Nome do módulo: 		Ball
 * Ano de criação: 		2018/10
 * Descrição do módulo: Classe que representa a bola do jogo.
 * 						Possui um vetor de pontos antigos da bola para fazer a predição.
 * 						O método de predição ofensivo desconsidera se a bola está próxima do jogador.
 * Versão: 				1.0
 * Pré-requisitos: 		Agent 
 * 						TeamPlayer
 * 						vector (biblioteca padrão)
 * 						iostream (biblioteca padrão)
 * Membros: 			Lorena Bassani
 * 						Victor de Oliveira
 */

#include "agent.h"
#include "teamplayer.h"

#include <vector>
#include <iostream>

namespace vsssERUS{
	class Ball: public Agent
	{
	public:
		Ball(double x, double y);
		Ball(Ponto p);

		/* Nome da função :		predictBall
		 * Intenção da função:	Função vinda do código original (ainda a descobrir suas intenções)
		 * Pré-requisitos:		Nenhum
		 * Efeitos colaterais:	Nenhum
		 * Parâmetros:			TeamPlayer : jogador
		 * Retorno:				Ponto : ponto retornado
		 */
		Ponto predictBall(TeamPlayer& player);

		/* Nome da função:		predictBallOffensive
		 * Intenção da função:	Função vinda do código original (ainda a descobrir suas intenções)
		 * Pré-requisitos:		Nenhum
		 * Efeitos colaterais:	Nenhum
		 * Parâmetros:			TeamPlayer : jogador
		 * Retorno:				Ponto : ponto retornado
		 */
		Ponto predictBallOffensive(TeamPlayer& player);
	};
}
#endif // BALL_H
