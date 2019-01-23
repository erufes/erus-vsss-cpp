#ifndef DEFESABEHAVIOR_H_
#define DEFESABEHAVIOR_H_
#include "playbehavior.h"
#include "ponto.h"

	namespace vsssERUS{
	class World;
	/* Nome do m�dulo: DefesaBehavior
	* Ano de cria��o: 2018/12
	* Descri��o do m�dulo: cria o comportamento do jogador defensor
	* Vers�o: 1.0
	* Pr�-requisitos: nenhum
	* Membros: Ricardo Ramos
	*/


	class DefesaBehavior:public PlayBehavior{
	public:
		DefesaBehavior();
		virtual ~DefesaBehavior();

		/* movimenta
		* Inten��o da fun��o: Calcular onde o defensor dever� ir
		* Pr�-requisitos: Posi��o v�lida do defensor, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do defensor
		* Retorno: Posi��o para onde o defensor dever� se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Inten��o da fun��o: Calcular velocidade do defensor para ir at� a posi�ao desejada
		* Pr�-requisitos: Posi��o v�lida do defensor, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o para onde o defensor dever� ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);
	};
}
#endif /* DEFESABEHAVIOR_H_ */
