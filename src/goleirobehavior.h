#ifndef GOLEIROBEHAVIOR_H_
#define GOLEIROBEHAVIOR_H_
#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS{
	class World;
	/* Nome do m�dulo: GoleiroBehavior
	* Ano de cria��o: 2018/12
	* Descri��o do m�dulo: cria o comportamento do goleiro
	* Vers�o: 1.0
	* Pr�-requisitos: nenhum
	* Membros: Ricardo Ramos
	*/

	class GoleiroBehavior:public PlayBehavior{
	public:
		GoleiroBehavior();
		virtual ~GoleiroBehavior();

		/* movimenta
		* Inten��o da fun��o: Calcular onde o goleiro dever� ir
		* Pr�-requisitos: Posi��o v�lida do goleiro, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do goleiro
		* Retorno: Posi��o para onde o goleiro dever� se movimentar
		*/
		Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Inten��o da fun��o: Calcular velocidade do goleiro para ir at� a posi�ao desejada
		* Pr�-requisitos: Posi��o v�lida do goleiro, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o para onde o goleiro dever� ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		std::pair<int,int> controle(Ponto posicao, World* mundo);
	};
}
#endif /* GOLEIROBEHAVIOR_H_ */
