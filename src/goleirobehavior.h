#ifndef GOLEIROBEHAVIOR_H
#define GOLEIROBEHAVIOR_H
#include "playbehavior.h"
#include "ponto.h"

/* Nome do módulo: GoleiroBehavior
* Ano de criação: 2018/12
* Descrição do módulo: cria o comportamento do goleiro
* Versão: 1.0
* Pré-requisitos: nenhum
* Membros: Ricardo Ramos
*/
namespace vsssERUS{
class World;

class GoleiroBehavior : public PlayBehavior{
public:
	GoleiroBehavior();
	~GoleiroBehavior()=default;

	/* movimenta
	* Intenção da função: Calcular onde o goleiro deverá ir
	* Pré-requisitos: Posição válida do goleiro, dentro do campo
	* Efeitos colaterais: Não possui efeitos colaterais
	* Parametros: Posição atual do goleiro
	* Retorno: Posição para onde o goleiro deverá se movimentar
	*/
	Ponto movimenta(Ponto posicao, World* mundo);

	/* controle
	* Intenção da função: Calcular velocidade do goleiro para ir até a posição desejada
	* Pré-requisitos: Posição válida do goleiro, dentro do campo
	* Efeitos colaterais: Não possui efeitos colaterais
	* Parametros: Posição para onde o goleiro deverá ir
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
#endif // GOLEIROBEHAVIOR_H
