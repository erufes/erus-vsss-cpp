#ifndef DEFESABEHAVIOR_H_
#define DEFESABEHAVIOR_H_
#include "playbehavior.h"
#include "ponto.h"

class World;
/* Nome do módulo: DefesaBehavior
 * Ano de criação: 2018/12
 * Descrição do módulo: cria o comportamento do jogador defensor
 * Versão: 1.0
 * Pré-requisitos: nenhum
 * Membros: Ricardo Ramos
 */


class DefesaBehavior:public PlayBehavior{
public:
	DefesaBehavior();
	virtual ~DefesaBehavior();

	/* movimenta
	 * Intenção da função: Calcular onde o defensor deverá ir
	 * Pré-requisitos: Posição válida do defensor, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição atual do defensor
	 * Retorno: Posição para onde o defensor deverá se movimentar
	 */
	Ponto movimenta(Ponto posicao, World* mundo);

	/* controle
	 * Intenção da função: Calcular velocidade do defensor para ir até a posiçao desejada
	 * Pré-requisitos: Posição válida do defensor, dentro do campo
	 * Efeitos colaterais: Não possui efeitos colaterais
	 * Parametros: Posição para onde o defensor deverá ir
	 * Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
	 */
	std::pair<int,int> controle(Ponto posicao, World* mundo);
};

#endif /* DEFESABEHAVIOR_H_ */
