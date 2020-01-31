#ifndef GOLEIROBEHAVIOR_H_
#define GOLEIROBEHAVIOR_H_

/* Nome do módulo :         GoleiroBehavior
 * Ano de criação :         2018/12
 * Descrição do módulo :    cria o comportamento do goleiro
 * Versão:                  1.0
 * Pré-requisitos:          PlayBehaviour
 *                          Ponto
 * Membros:                 Lorena Bassani
 *                          Ricardo Ramos
 */
#include "playbehavior.h"
#include "ponto.h"

namespace vsssERUS{
    class World;

    class GoleiroBehavior : public PlayBehavior{
    public:
        GoleiroBehavior();
        ~GoleiroBehavior()=default;

        /* Nome da Função :     movimenta
         * Intenção da função : Calcular onde o goleiro deverá ir
         * Pré-requisitos :     Posição válida do goleiro dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição atual do goleiro
         *                      World : Mundo com as informações de jogo
         * Retorno :            Ponto : Posição para onde o goleiro deverá se movimentar
         */
        Ponto movimenta(Ponto posicao, World* mundo);

        /* Nome da Função :     controle
         * Intenção da função : Calcular velocidade do goleiro para ir até a posição desejada
         * Pré-requisitos :     Posição válida do goleiro dentro do campo
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : Posição para onde o goleiro deverá ir
         *                      World : Mundo com as informações de jogo
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
#endif /* GOLEIROBEHAVIOR_H_ */
