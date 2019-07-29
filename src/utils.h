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
     * Transforma um ângulo de [-PI, PI] para [0, 2PI]
     *
     */
    double toPositiveAngle(double angle) {
        return fmod(angle + 2 * M_PI, 2 * M_PI);
    }

    /**
     * @brief Retorna a menor distância angular entre dois ângulos
     *
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
     * Transforma um ângulo para o domínio [-PI, PI]
     *
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
     * Retorna a distância entre dois pontos
     *
     */
    double distance(doublePair first, doublePair second) {
        return std::sqrt(std::pow(first.first - second.first, 2) + std::pow(first.second - second.second, 2));
    }

    /**
     * @brief Transforma o valor x para o domínio [low, high]
     *
     */
    double bound (double x, double low, double high) {
        if (x < low) x = low;
        if (x > high) x = high;
        return x;
    }
}

#endif