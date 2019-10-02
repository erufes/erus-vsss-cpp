#ifndef DEFESABEHAVIOR_H
#define DEFESABEHAVIOR_H
#include "playbehavior.h"
#include "ponto.h"

/* Nome do módulo: DefesaBehavior
* Ano de criação: 2018/12
* Descrição do módulo: cria o comportamento do jogador defensor
* Versão: 1.0
* Pré-requisitos: nenhum
* Membros: Ricardo Ramos
*/
namespace vsssERUS {

class DefesaBehavior : public PlayBehavior {
	public:
		DefesaBehavior();
		~DefesaBehavior();

		/* movimenta
		* Intenção da função: Calcular onde o defensor deverá ir
		* Pré-requisitos: Posição válida do defensor, dentro do campo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do defensor
		* Retorno: Posição para onde o defensor deverá se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Intenção da função: Calcular velocidade do defensor para ir até a posição desejada
		* Pré-requisitos: Posição válida do defensor, dentro do campo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição para onde o defensor deverá ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direita e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);

				/* sairDaParede
		* Intenção da função: Impedir colisão do robô com a parede
		* Pré-requisitos: Campo correto em mundo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô e mundo
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		std::pair<int,int> sairDaParede(Ponto posicao, World* mundo);

		/* evitarColisaoEntreJogadores
		* Intenção da função: Impedir colisão do robô com outro robô
		* Pré-requisitos: Posição dos jogadores correta em mundo
		* Efeitos colaterais: Não possui efeitos colaterais
		* Parametros: Posição atual do robô e mundo
		* Retorno: Posição para onde o robô deverá se movimentar
		*/
		std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo);
	};

} // vsssERUS

#endif // DEFESABEHAVIOR_H
