#ifndef GOLEIROBEHAVIOR_H_
#define GOLEIROBEHAVIOR_H_
#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS{
	class World;
	/* Nome do módulo: GoleiroBehavior
	* Ano de criação: 2018/12
	* Descrição do módulo: cria o comportamento do goleiro
	* Versão: 1.0
	* Pré-requisitos: nenhum
	* Membros: Ricardo Ramos
	*/

	class GoleiroBehavior:public PlayBehavior{
	public:
		GoleiroBehavior();
		virtual ~GoleiroBehavior()=default;

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
	};
}
#endif /* GOLEIROBEHAVIOR_H_ */
