#ifndef UTILS_H
#define UTILS_H

#include <math.h>
#include <utility>

#define doublePair std::pair <double, double>

namespace Utils {

    /**
     * Estrutura para guardar as informações de uma posição.
     *
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

    double toPositiveAngle(double angle);

    double smallestAngleDiff(double target, double source);

    double to180range(double angle);

    double distance(doublePair first, doublePair second);

    double bound (double x, double low, double high);
};

#endif