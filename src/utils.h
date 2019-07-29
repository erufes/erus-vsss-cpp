#ifndef UTILS_H
#define UTILS_H

#include <math.h>

#define doublePair std::pair <double, double>

namespace Utils {

    /**
     * Estrutura para guardar as informações de uma posição.
     *
     */
    typedef struct Posture {
        double x, y, angle;

        Posture(double x, double y, double angle) {
            this->x = x;
            this->y = y;
            this->angle = angle;
        }

    } Posture;

    /**
    * Nome da função:       toPositiveAngle;
    * Intenção da função:   Transforma um ângulo de [-PI, PI] para [0, 2PI];
    * Pré-requisitos:       O angulo tem que está entre [-PI, PI];
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) angle: ângulo a ser transformado;
    * Retorno:              (double) angle: ângulo transformado;
    */

    double toPositiveAngle(double angle) {
        return fmod(angle + 2 * M_PI, 2 * M_PI);
    }


        /**
        * Nome da função:       smallestAngleDiff;
        * Intenção da função:   Retorna a menor distância angular entre dois ângulos;
        * Pré-requisitos:       Necessitar da diferença entre dois ângulos;
        * Efeitos colaterais:   Não há;
        * Parâmetros:           (double) target: ângulo alvo;
        *                       (double) source: ângulo fonte;
        * Retorno:              (double) a: distancia ângular entre os dois ângulos;
        */

    double smallestAngleDiff(double target, double source) {
        double a = Utils::toPositiveAngle(target) - Utils::toPositiveAngle(source);
        if (a > M_PI) {
            a = a - 2 * M_PI;
        }
        else if (a < -M_PI) {
            a = a + 2 * M_PI;
        }
        return a;
    }

    /**
    * Nome da função:       to180range;
    * Intenção da função:   Transforma um ângulo para o domínio [-PI, PI];
    * Pré-requisitos:       O angulo está num domínio diferente de [-PI, PI];
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) angle: ângulo ser transformado;
    * Retorno:              (double) angle: ângulo transformado;
    */

    double to180range(double angle) {
        angle = fmod(angle, 2 * M_PI);
        if (angle < - M_PI) {
            angle = angle + 2 * M_PI;
        } else if (angle > M_PI) {
            angle = angle - 2 * M_PI;
        }
        return angle;
    }

    /**
    * Nome da função:       distance;
    * Intenção da função:   Retorna a distância entre dois pontos;
    * Pré-requisitos:       Necessitar da diferença entre dois ângulos;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) first: primeiro ângulo;
    *                       (double) second: primeiro ângulo;
    * Retorno:              Um numero (double), que é a distância entre o first e o second;
    */

    double distance(doublePair first, doublePair second) {
        return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
    }

    /**
    * Nome da função:       bound;
    * Intenção da função:   Transforma o valor x para o domínio [low, high];
    * Pré-requisitos:       traduzir x em um valor high ou low;
    * Efeitos colaterais:   Não há;
    * Parâmetros:           (double) x: numero a ser transformado;
    *                       (double) low: numero de comparação;
    *                       (double) high: numero de comparação;
    * Retorno:              (double) x: numero transformado;
    */

    double bound (double x, double low, double high) {
        if (x < low) x = low;
        if (x > high) x = high;
        return x;
    }
}

#endif
