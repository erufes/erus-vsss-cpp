//tstado!! Selo Valdino de Garantia \0/
//Nota: ponto só salva 5 casas decimais

#ifndef PONTO_H
#define PONTO_H
/* Nome do módulo: Ponto
 * Ano de criação: 2018/10
 * Descrição do módulo: Criação dos pontos mais uma função extra para resolver sistemas lineares de ordem N
 * Versão: 1.1
 * Pré-requisitos: Coordenadas dos pontos não negativas
 * Membros: Ricardo Ramos, Gabriel Valdino
 */
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Ponto
{
    double x;
    double y;
public:
    Ponto(double x = 0, double y = 0);

    /* distancia
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    double distancia(Ponto outro);

    /* getX
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    double getX();

    /* getY
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    double getY();

    /* setX
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    void setX(double x);

    /* setY
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    void setY(double y);

    /* resolucaoDeSistemaLinear
	 * Intenção da função:
	 * Pré-requisitos:
	 * Efeitos colaterais:
	 * Parametros:
	 * Retorno:
	 */
    //Resolução do sistema Ax = b, sendo A = matrix, b = vetor, N = ordem de matrix
    //Atenção à chamada da função, pois ela precisa de um "double** A" e não um "double A[N][N]", logo, é necessário o uso de mallocs
    //Créditos à professora Cláudia Galarda Varassin pela criação da função que foi poucamente modificada para atender à nossos anseios
    static vector<double> resolucaoDeSistemaLinear(double** matrix, double* vetor, int N);
};

#endif // PONTO_H
