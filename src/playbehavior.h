#ifndef PLAYBEHAVIOR_H_
#define PLAYBEHAVIOR_H_


/* Nome do módulo :         PlayBehavior
 * Ano de criação :         2018/12
 * Descrição do módulo :    Interface para o comportamento do jogador
 * Versão :                 1.0
 * Pré-requisitos :         Ponto
 *                          utility (biblioteca padrão)
 * Membros :                Ricardo Ramos
 */

#include <utility>
#include "ponto.h"

namespace vsssERUS {
class World;
class PlayBehavior {
    public:
        virtual ~PlayBehavior(){};

        /* Nome da função :     movimenta
         * Intenção da função : Calcular onde o robô deverá ir
         * Pré-requisitos :     Posição válida do robô dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do robô
         *                      World : Mundo com as informações de jogo
         * Retorno :            Ponto : Posição para onde o robô deverá se movimentar
         */
        virtual Ponto movimenta(Ponto posicao, World* mundo) = 0;

        /* Nome da Função :     controle
         * Intenção da função : Calcular velocidade do robô para ir até a posição desejada
         * Pré-requisitos :     Posição válida do robô dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição para onde o robô deverá ir
         *                      World : Mundo com as informações de jogo
         * Retorno:             pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
         */
        virtual std::pair<int,int> controle(Ponto posicao, World* mundo) = 0;

        /* Nome da Função :     sairDaParede
         * Intenção da função : Impedir colisão do robô com a parede
         * Pré-requisitos :     Campo correto em mundo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do robô
         *                      World : Mundo com as informações de jogo
         * Retorno :            pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
         */
        virtual std::pair<int,int> sairDaParede(Ponto posicao, World* mundo) = 0;

        /* Nome da Função :     evitarColisaoEntreJogadores
         * Intenção da função : Impedir colisão do robô com outro robô
         * Pré-requisitos :     Posição dos jogadores correta em mundo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do robô
         *                      World : Mundo com as informações de jogo
         * Retorno :            pair<int, int> : velocidades das rodas, primeiro a direita e segundo a esquerda
         */
        virtual std::pair<int,int> evitarColisaoEntreJogadores(Ponto posicao, World* mundo) = 0;

        /* Nome da função :     ballFetch
        * Intenção da função : Levar o robô até a bola
        * Pré-requisitos :     Posição válida do robô dentro do campo
        * Efeitos colaterais : Nenhum
        * Parametros :         Ponto : Posição atual do robô
        *                      World : Mundo com as informações de jogo
        * Retorno :            Ponto : Posição para onde o robô deverá se movimentar
        */
        virtual Ponto ballFetch(Ponto posicao, World* mundo);
    };
}
#endif /* PLAYBEHAVIOR_H_ */


