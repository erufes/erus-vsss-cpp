#ifndef AGENT_H
#define AGENT_H

/* Nome:                Agent
 * Ano de criação:      2018/10
 * Descrição do módulo: Representa objetos no campo (bola, jogadores, etc..), clase abstrata que reune informações desses objeto e abstrai o tipo de objeto que se trata.
 * Versão:              1.2
 * Pré-requisitos:      Ponto
 *                      vector (biblioteca padrão)
 *                      cstdlib (biblioteca padrão)
 *                      iostream (biblioteca padrão)
 * Membros:             Gabriel Valdino
 *                      Lorena Bassani
 *                      Ricardo Ramos
 */

#include "ponto.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace vsssERUS{
    class Agent
    {
        Ponto posicao;
        vector<Ponto> posicoesAnteriores;
    public:
        Agent(double x = 0, double y = 0);
        Agent(Ponto ponto);
        virtual ~Agent(){};

        /* 
         * Nome da função:       getxyOld
         * Intenção da função:   Retorna o vetor de posições anteriores
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           Nenhum
         * Retorno:              vector<Ponto> : posicoesAnteriores: vetor de posições anteriores
         */
        vector<Ponto> getxyOld() const;

        /*
         * Nome da função:       previsaoDePosicao
         * Intenção da função:   Faz a previsão de uma futura posição da bola/player
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           Nenhum
         * Retorno:              pair<double, double> : localização futura predita
         */
        virtual std::pair<double, double> previsaoDePosicao() const;

        /*
         * Nome da função:       updatePosition
         * Intenção da função:   Atualização da posição do robô
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           double : posição no eixo x
         *                       double : posição no eixo y                      
         * Retorno:              Nenhum
         */
        void updatePosition(double x, double y);

        /*
         * Nome da função:       updatePosition
         * Intenção da função:   Atualização da posição do robô
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           Ponto ponto: Ponto representado pelas coordenadas X e Y;
         * Retorno:              Nenhum
         */
        void updatePosition(Ponto ponto);

        /*
         * Nome da função:       getPosicao
         * Intenção da função:   Função que retorna a posição atual
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           Nenhum
         * Retorno:              Ponto : posição atual
         */
        Ponto getPosicao() const;

        /*
         * Nome da função:       distancia
         * Intenção da função:   Função que retorna a distância entre dois objetos da classe Agent
         * Pré-Requisitos:       Nenhum
         * Efeitos colaterais:   Nenhum
         * Parâmetros:           Agent : agente para o qual se deseja calcular a distância;
         * Retorno:              float : Distância calculada;
         */
        float distancia(Agent& agente) const;
    };
}
#endif // AGENT_H
