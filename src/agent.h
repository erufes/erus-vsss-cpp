//tstado!! Selo Valdino de Garantia \0/
//Por enquanto, para que a função “previsaoDePosicao” funcione adequadamente, é necessário 5 updates de posição para o agente em questão. Futuramente, isso poderá ser mudado.

#ifndef AGENT_H
#define AGENT_H

/* Nome: Agente
 * Ano de criação: 2018/10
 * Descrição do módulo: Representa objetos no campo (bola, jogadores, etc..), clase abstrata que reune informações desses objeto e abstrai o tipo de objeto que se trata.
 * Versão: 1.1
 * testado!! Selo Valdino de Garantia \0/
 * Pré-requisitos: NULL
 * Membros: Ricardo Ramos, Gabriel Valdino
 */

#include "ponto.h"
#include <vector>

using namespace std;

class Agent
{
    Ponto posicao;
    vector<Ponto> old;
public:
    Agent(double x = 0, double y = 0);
    Agent(Ponto ponto);
    virtual ~Agent(){};

    /* getxy_old
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    vector<Ponto> getxy_old();

    /* previsaoDePosicao
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    virtual std::pair<double, double> previsaoDePosicao(Ponto ponto_atual, vector<Ponto> vetor_funcao);
    virtual std::pair<double, double> previsaoDePosicao() = 0;

    /* update_position
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    void update_position(double x, double y);
    void update_position(Ponto ponto);

    /* getPonto
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    Ponto getPonto();

private:
    /* ajusteDeCurva
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    double** ajusteDeCurva(vector<Ponto> vet, int grau);
};

#endif // AGENT_H
