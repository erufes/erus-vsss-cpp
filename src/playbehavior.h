#ifndef PLAYBEHAVIOR_H_
#define PLAYBEHAVIOR_H_
#include <utility>
#include "ponto.h"

	namespace vsssERUS{
	/* Nome do m�dulo: PlayBehavior
	* Ano de cria��o: 2018/12
	* Descri��o do m�dulo: classe abstrata para o comportamento do jogador
	* Vers�o: 1.0
	* Pr�-requisitos: nenhum
	* Membros: Ricardo Ramos
	*/
	class World;
	class PlayBehavior {
	public:
		PlayBehavior();
		virtual ~PlayBehavior();

		/* movimenta
		* Inten��o da fun��o: Calcular onde o rob� dever� ir
		* Pr�-requisitos: Posi��o v�lida do rob�, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do rob�
		* Retorno: Posi��o para onde o rob� dever� se movimentar
		*/
		virtual Ponto movimenta(Ponto posicao, World* mundo);

		/* controle
		* Inten��o da fun��o: Calcular velocidade do rob� para ir at� a posi�ao desejada
		* Pr�-requisitos: Posi��o v�lida do rob�, dentro do campo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o para onde o rob� dever� ir
		* Retorno: Par de inteiros representado as velocidades das rodas, primeiro a direira e segundo a esquerda
		*/
		virtual std::pair<int,int> controle(Ponto posicao, World* mundo);

		/* sairDaParede
		* Inten��o da fun��o: Impedir colis�o do rob� com a parede
		* Pr�-requisitos: Campo correto em mundo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do rob� e mundo
		* Retorno: Posi��o para onde o rob� dever� se movimentar
		*/
		virtual std::pair<int,int> sairDaParede(Ponto posicao, World* mundo);

		/* evitarColisaoEntreJogadores
		* Inten��o da fun��o: Impedir colis�o do rob� com outro rob�
		* Pr�-requisitos: Posi��o dos jogadores correta em mundo
		* Efeitos colaterais: N�o possui efeitos colaterais
		* Parametros: Posi��o atual do rob� e mundo
		* Retorno: Posi��o para onde o rob� dever� se movimentar
		*/
		virtual std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo);
	};
}
#endif /* PLAYBEHAVIOR_H_ */


