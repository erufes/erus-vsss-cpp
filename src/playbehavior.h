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

class PlayBehavior {
public:
	PlayBehavior();
	virtual ~PlayBehavior();

	/* movimenta
	 * Intenção da função: Calcular onde o robô deverá ir
	 * Pré-requisitos: Posição válida do robô, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição atual do robô
	 * Retorno: Posição para onde o robô deverá se movimentar
	 */
	//virtual Ponto movimenta(Ponto posicao);

	/* controle
	 * Intenção da função: Calcular velocidade do robô para ir até a posiçao desejada
	 * Pré-requisitos: Posição válida do robô, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição para onde o robô deverá ir
	 * Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
	 */
	//virtual std::pair<int,int> controle(Ponto posicao);
};

#endif /* PLAYBEHAVIOR_H_ */
