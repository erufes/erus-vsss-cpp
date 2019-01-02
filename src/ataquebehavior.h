#ifndef ATAQUEBEHAVIOR_H_
#define ATAQUEBEHAVIOR_H_
#include "playbehavior.h"

class World;
/* Nome do módulo: AtaqueBehavior
 * Ano de criação: 2018/12
 * Descrição do módulo: cria o comportamento do jogador atacante
 * Versão: 1.0
 * Pré-requisitos: nenhum
 * Membros: Ricardo Ramos
 */

class AtaqueBehavior: public PlayBehavior{
public:
	AtaqueBehavior();
	virtual ~AtaqueBehavior();

	/* movimenta
	 * Intenção da função: Calcular onde o atacante deverá ir
	 * Pré-requisitos: Posição válida do atacante, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição atual do atacante
	 * Retorno: Posição para onde o atacante deverá se movimentar
	 */
	Ponto movimenta(Ponto posicao, World mundo);

	/* controle
	 * Intenção da função: Calcular velocidade do atacante para ir até a posiçao desejada
	 * Pré-requisitos: Posição válida do atacante, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição para onde o atacante deverá ir
	 * Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
	 */
	std::pair<int,int> controle(Ponto posicao, World mundo);
};

#endif /* ATAQUEBEHAVIOR_H_ */
