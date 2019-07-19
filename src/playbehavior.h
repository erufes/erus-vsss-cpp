#ifndef PLAYBEHAVIOR_H_
#define PLAYBEHAVIOR_H_
#include <utility>
#include "ponto.h"
#include "world.h"

/* Nome do módulo: PlayBehavior
 * Ano de criação: 2018/12
 * Descrição do módulo: classe abstrata para o comportamento do jogador
 * Versão: 1.0
 * Pré-requisitos: nenhum
 * Membros: Ricardo Ramos
*/

namespace vsssERUS{
	
class PlayBehavior {
	public:
		virtual ~PlayBehavior() = 0;

		/* movimenta
		* Intenção da função: Calcular onde o robô deverá ir
		* Pré-requisitos: Posição válida do robô, dentro do campo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		virtual Ponto movimenta(Ponto posicao, World* mundo) = 0;

		/* controle
		* Intenção da função: Calcular velocidade do robô para ir até a posição desejada
		* Pré-requisitos: Posição válida do robô, dentro do campo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição para onde o robô deverá ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direita e segundo a esquerda
		*/
		virtual std::pair<int,int> controle(Ponto posicao, World* mundo) = 0;

		/* sairDaParede
		* Intenção da função: Impedir colisão do robô com a parede
		* Pré-requisitos: Campo correto em mundo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô e mundo
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		virtual std::pair<int,int> sairDaParede(Ponto posicao, World* mundo) = 0;

		/* evitarColisaoEntreJogadores
		* Intenção da função: Impedir colisão do robô com outro robô
		* Pré-requisitos: Posição dos jogadores correta em mundo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô e mundo
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		virtual std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo) = 0;
	};
}
#endif /* PLAYBEHAVIOR_H_ */


