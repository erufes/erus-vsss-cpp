#ifndef ATAQUEBEHAVIOR_H_
#define ATAQUEBEHAVIOR_H_
#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS{
	class World;
	/* Nome do m�dulo: AtaqueBehavior
	* Ano de cria��o: 2018/12
	* Descri��o do m�dulo: cria o comportamento do jogador atacante
	* Vers�o: 1.0
	* Pr�-requisitos: nenhum
	* Membros: Ricardo Ramos
	*/

	class AtaqueBehavior:public PlayBehavior{
	public:
		AtaqueBehavior();
		virtual ~AtaqueBehavior();

		/* movimenta
		* Inten��o da fun��o: Calcular onde o atacante dever� ir
		* Pr�-requisitos: Posi��o v�lida do atacante, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do atacante
		* Retorno: Posi��o para onde o atacante dever� se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Inten��o da fun��o: Calcular velocidade do atacante para ir at� a posi�ao desejada
		* Pr�-requisitos: Posi��o v�lida do atacante, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o para onde o atacante dever� ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);
	};
}
#endif /* ATAQUEBEHAVIOR_H_ */
