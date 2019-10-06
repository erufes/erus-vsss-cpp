#ifndef PLAYER_H
#define PLAYER_H


/* Nome do módulo :     Player
 * Ano de criação :     2018/11
 * Descrição do módulo: Cria o player com as posições antigas salvas e theta (o ângulo referente ao lado inferior do campo)
 *                      Classe Abstrata para que não seja instanciada, uma vez que serve de abstração de robôs do time (TeamPlayer) ou inimigos (Enemy).
 *                      Seu funcionamento lembra uma DataClass pois guarda e recupera informações como posição e id.
 * Versão :             1.1
 * Pré-requisitos :     Agent
 * Membros:             Gabriel Valdino
 *                      Lorena Bassani 
 *                      Victor de Oliveira
 */

#include "agent.h"

namespace vsssERUS{
    class Player: public Agent {
        double theta;
        double thetaAntigo;
        int id;
        float erroAtual;
        float erroAntigo;
    public:

        Player(int id = 0,double theta = 0.0);

        /* Nome da Função :     getId
         * Intenção da Função : Retornar o Id do robô
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            int : Id do robô
         */
        int getId() const;

        /* Nome da Função :     getPosicaoAntiga
         * Intenção da Função : Retorna a Posição anterior
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            Ponto : ponto anterior ocupado pelo robô
         */
        Ponto getPosicaoAntiga() const;

        /* Nome da Função :     getTheta
         * Intenção da Função : Retornar o angulo do robô
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            double : angulo do robô
         */
        double getTheta() const;

        /* Nome da Função :     setTheta
         * Intenção da Função : Atualizar o angulo do robô
         * Pré-requisitos :     angulo entre 0 e 2π
         * Efeitos colaterais : Altera a informação de angulo do robô
         * Parâmetros :         double : novo angulo
         * Retorno :            Nenhum
         */
        void setTheta(double theta);

        /* Nome da Função :     getThetaAntigo
         * Intenção da Função : Retorna o angulo anterior do robô
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            double : angulo anterior do robô
         */
        double getThetaAntigo() const;

        /* Nome da Função :     isEnemy
         * Intenção da Função : Saber se o jogador é inimigo ou aliado
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parâmetros :         Nenhum
         * Retorno :            bool : true se for inimigo, false caso contrário
         */
        virtual bool isEnemy() = 0;

    };
}
#endif // PLAYER_H
