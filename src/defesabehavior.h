#ifndef DEFESABEHAVIOR_H_
#define DEFESABEHAVIOR_H_

/* Nome do módulo :         DefesaBehavior
 * Ano de criação :         2018/12
 * Descrição do módulo :    cria o comportamento do jogador defensor
 * Versão :                 1.3
 * Pré-requisitos :         PlayBehaviour
 *                          Ponto
 * Membros :                Lorena Bassani
 *                          Ricardo Ramos
 */

#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS {

class DefesaBehavior : public PlayBehavior {
    public:
        DefesaBehavior();
        ~DefesaBehavior();

        /* Nome da Função :     movimenta
         * Intenção da função : Calcular onde o defensor deverá ir
         * Pré-requisitos:      Posição válida do defensor, dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do defensor
         *                      World : Mundo com as informações de Jogo
         * Retorno :            Ponto : Posição para onde o defensor deverá se movimentar
         */
        Ponto movimenta(Ponto posicao, World* mundo);

        /* Nome da Função :     controle
         * Intenção da função : Calcular velocidade do defensor para ir até a posição desejada
         * Pré-requisitos :     Posição válida do defensor, dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição para onde o defensor deverá ir
         *                      World : Mundo com as informações de Jogo
         * Retorno :            pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
         */
        std::pair<int,int> controle(Ponto posicao, World* mundo);

        /* Nome da Função :     sairDaParede
         * Intenção da função : Impedir colisão do robô com a parede
         * Pré-requisitos :     Campo correto em mundo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do robô 
         *                      World : Mundo com as informações de Jogo
         * Retorno :            pair<int, int> : velocidade a qual o robô deverá se movimentar
         */
        std::pair<int,int> sairDaParede(Ponto posicao, World* mundo);

        /* Nome da Função :     evitarColisaoEntreJogadores
         * Intenção da função : Impedir colisão do robô com outro robô
         * Pré-requisitos :     Posição dos jogadores correta em mundo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do robô 
         *                      World : Mundo com as informações de Jogo
         * Retorno:             pair<int, int> : velocidade a qual o robô deverá se movimentar
         */
        std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo);
    };

}
#endif /* DEFESABEHAVIOR_H_ */
