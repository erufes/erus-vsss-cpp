#ifndef AGENT_H
#define AGENT_H

/* Nome: Agente
 * Ano de criação: 2018/10
 * Descrição do módulo: Representa objetos no campo (bola, jogadores, etc..), clase abstrata que reune informações desses objeto e abstrai o tipo de objeto que se trata.
 * Versão: 1.2
 * Pré-requisitos: NULL
 * Membros: Ricardo Ramos, Gabriel Valdino
 */

#include "ponto.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace vsssERUS {
class Agent
{
    Ponto posicao;
    vector<Ponto> posicoesAnteriores;
public:
    Agent(double x = 0, double y = 0);
    Agent(Ponto ponto);
    virtual ~Agent(){};

    /* 
    * Nome da função:       getxyOld;
    * Intenção da função:   Retorna o vetor de posições anteriores;
    * Pré-Requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           Não há;
    * Retorno:              (vector<Ponto>) posicoesAnteriores: vetor de posições anteriores;
    */
    vector<Ponto> getxyOld() const;

    /*
    * Nome da função:       previsaoDePosicao;
    * Intenção da função:   Faz a previsão de uma futura posição da bola/player;
    * Pré-Requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           Não há;
    * Retorno:              pair<double, double> ponto_futuro: localização futura predita;
    */
    virtual std::pair<double, double> previsaoDePosicao() const;

    /*
    * Nome da função:       updatePosition
    * Intenção da função:   Atualização da posição do robô;
    * Pré-Requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) x:posição no eixo x
    *                       (double) y: posição no eixo y
    *                       ou
    *                       (Ponto) ponto: Ponto representado pelas coordenadas X e Y;
    * Retorno:              void;
    */
    void updatePosition(double x, double y);
    void updatePosition(Ponto ponto);

    /*
    * Nome da função:       getPosicao;
    * Intenção da função:   Função que chama a posição atual;
    * Pré-Requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           Não há;
    * Retorno:              (Ponto) posição: posição atual;
    */
    Ponto getPosicao() const;

    /*
    * Nome da função:       distancia;
    * Intenção da função:   Função que retorna a distância entre dois objetos da classe Agent;
    * Pré-Requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (Agent&) agente: agente para o qual se deseja calcular a distância;
    * Retorno:              (float) d: Distância calculada;
    */
    float distancia(Agent& agente) const;
};

} /* vsssERUS */

#endif // AGENT_H
