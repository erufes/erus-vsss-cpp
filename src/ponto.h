#ifndef PONTO_H
#define PONTO_H
/* Nome do módulo:      Ponto
 * Ano de criação:      2018/10
 * Descrição do módulo: Definição de Pontos no campo
 * Versão:              1.1
 * Pré-requisitos:      cmath (biblioteca padrão)
 *                      vector (biblioteca padrão)
 *                      iostream (biblioteca padrão)
 *                      cstdio (biblioteca padrão)
 * Membros:             Gabriel Valdino
 *                      Gabriel Pitroluongo
 *                      Ricardo Ramos
 */
#include <cmath>
#include <vector>
#include <iostream>
#include <cstdio>
#define DOUBLE_CMP_THRESHOLD 0.000000000000001

using namespace std;
    namespace vsssERUS{
    class Ponto
    {
        double x;
        double y;
    public:
        Ponto(double x = 0, double y = 0);

        /* Nome da Função :     distancia
         * Intenção da função : Calcular distância entre pontos
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : ponto para calcular a distância
         * Retorno :            double : distância entre os pontos
         */
        double distancia(Ponto outro) const;

        /* Nome da Função :     getX
         * Intenção da função : Retornar a coordenada x do ponto
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parametros :         Nenhum
         * Retorno :            double : coordenada x do ponto
         */
        double getX() const;

        /* Nome da Função :     getY
         * Intenção da função : Retornar a coordenada y do ponto
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parametros :         Nenhum
         * Retorno :            double : coordenada y do ponto
         */
        double getY() const;

        /* Nome da Função :     setX
         * Intenção da função : Altera a coordenada x do ponto
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Altera o valor do atributo x do ponto
         * Parametros :         double : valor novo de x
         * Retorno :            Nenhum
         */
        void setX(double x);

        /* Nome da Função :     setY
         * Intenção da função : Altera a coordenada y do ponto
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Altera o valor do atributo y do ponto
         * Parametros :         double : valor novo de y
         * Retorno :            Nenhum
         */
        void setY(double y);

        /* Nome da Função :     static resolucaoDeSistemaLinear
         * Intenção da função : Resolver sistemas lineares do tipo Ax = b
         * Pré-requisitos :     Matriz matrix dinâmicamente alocada
         * Efeitos colaterais : Nenhum
         * Parametros :         double** : matriz A
         *                      double* : vetor B
         *                      int : numero máximo de iterações
         * Retorno :            vector<double> : resposta do sistema
         */
        //Resolução do sistema Ax = b, sendo A = matrix, b = vetor, N = ordem de matrix
        //Atenção à chamada da função, pois ela precisa de um "double** A" e não um "double A[N][N]", logo, é necessário o uso de mallocs
        //Créditos à professora Cláudia Galarda Varassin pela criação da função que foi poucamente modificada para atender aos nossos anseios
        static vector<double> resolucaoDeSistemaLinear(double** matrix, double* vetor, int N);

        /* Nome da Função :     Operador de igualdade (==) 
         * Intenção da função : Saber se pontos são iguais
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Nenhum
         * Parametros :         Ponto : o ponto a ser comparado
         * Retorno :            bool : true se os pontos tem as mesmas coordenadas, false caso contrário
         */
        bool operator==(Ponto const &p);
    };
}
#endif // PONTO_H
