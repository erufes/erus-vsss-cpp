#ifndef ATAQUEBEHAVIOR_H_
#define ATAQUEBEHAVIOR_H_

/* Nome do módulo: 		AtaqueBehavior
 * Ano de criação: 		2018/12
 * Descrição do módulo: cria o comportamento do jogador atacante
 * Versão: 				1.0
 * Pré-requisitos: 		PlayBehaviour (Interface)
 * 						Ponto
 * Membros: 			Ricardo Ramos
 */

#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS{
class AtaqueBehavior : public PlayBehavior {
	public:
		AtaqueBehavior();
		~AtaqueBehavior();

		/* Nome da Função : 	movimenta
		 * Intenção da função: 	Calcular onde o atacante deverá ir
		 * Pré-requisitos: 		Posição válida do atacante, dentro do campo
		 * Efeitos colaterais: 	Nenhum
		 * Parametros: 			Ponto : Posição atual do atacante
		 * 						World : Mundo com as informações de jogo
		 * Retorno: 			Ponto : Posição para onde o atacante deverá se movimentar
		 */
		Ponto movimenta(Ponto posicao, World* mundo);

		/* Nome da Função :		controle
		 * Intenção da função: 	Calcular velocidade do atacante para ir até a posição desejada
		 * Pré-requisitos: 		Posição válida do atacante, dentro do campo
		 * Efeitos colaterais: 	Nenhum
		 * Parametros: 			Ponto : Posição para onde o atacante deverá ir
		 * 						World : Mundo com as informações de jogo
		 * Retorno: 			pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
		 */
		std::pair<int,int> controle(Ponto posicao, World* mundo);

		/* Nome da Função :		sairDaParede
		 * Intenção da função: 	Impedir colisão do robô com a parede
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parametros: 			Ponto : Posição atual do robô
		 * 						World : Mundo com as informações de jogo
		 * Retorno: 			pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
		 */
		std::pair<int,int> sairDaParede(Ponto posicao, World* mundo);

		/* Nome da Função : 	evitarColisaoEntreJogadores
		 * Intenção da função: 	Impedir colisão do robô com outro robô
		 * Pré-requisitos: 		Nenhum
		 * Efeitos colaterais: 	Nenhum
		 * Parametros: 			Ponto : Posição atual do robô 
		 * 						World : Mundo com as informações de jogo
		 * Retorno: 			pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
		 */
		std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo);
	};
}
#endif /* ATAQUEBEHAVIOR_H_ */
