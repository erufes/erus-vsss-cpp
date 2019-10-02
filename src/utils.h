#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <utility>

#define doublePair std::pair <double, double>

namespace Utils {

/*
* Estrutura para guardar as informações de uma posição.
*/
struct Posture {
    double x, y, angle;
    public:
    Posture(double x, double y, double angle) {
        this->x = x;
        this->y = y;
        this->angle = angle;
    }
};

/*
    * Nome da função:       toPositiveAngle;
    * Intenção da função:   Transforma um ângulo de [-PI, PI] para [0, 2PI];
    * Pré-requisitos:       O ângulo deve estar entre [-PI, PI];
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) angle: ângulo a ser transformado;
    * Retorno:              (double) angle: ângulo transformado;
    */
double toPositiveAngle(double angle);

/*
    * Nome da função:       smallestAngleDiff;
    * Intenção da função:   Retorna a menor distância angular entre dois ângulos;
    * Pré-requisitos:       Necessitar da diferença entre dois ângulos;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) target: ângulo alvo;
    *                       (double) source: ângulo fonte;
    * Retorno:              (double) a: distancia ângular entre os dois ângulos;
    */
double smallestAngleDiff(double target, double source);

/*
    * Nome da função:       to180range;
    * Intenção da função:   Transforma um ângulo para o domínio [-PI, PI];
    * Pré-requisitos:       O angulo está num domínio diferente de [-PI, PI];
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) angle: ângulo ser transformado;
    * Retorno:              (double) angle: ângulo transformado;
    */
double to180range(double angle);

/*
    * Nome da função:       distance;
    * Intenção da função:   Retorna a distância entre dois pontos;
    * Pré-requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) first: coordenadas do primeiro ponto;
    *                       (double) second: coordenadas do segundo ponto;
    * Retorno:              (double) dist: distância entre o ponto "first" e o ponto "second";
    */
double distance(doublePair first, doublePair second);

/*
    * Nome da função:       bound;
    * Intenção da função:   Transforma o valor x para o domínio [low, high];
    * Pré-requisitos:       Não há;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) x: Número a ser transformado;
    *                       (double) low: Lower bound da transformação (mínimo valor do domínio);
    *                       (double) high: Upper bound da transformação (máximo valor do domínio);
    * Retorno:              (double) x: Número transformado;
    */
double bound (double x, double low, double high);

} // Utils
#endif
