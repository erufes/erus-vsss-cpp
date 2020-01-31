#ifndef UTILS_H
#define UTILS_H

/* Nome do módulo :         Utils
 * Ano de criação :         ??
 * Descrição do módulo :    Utilitários para Simulador
 * Versão :                 1.1
 * Pré-requisitos :         cmath
 *                          utility
 * Membros:                 Gabriel Pietroluongos
 */

#include <cmath>
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

    /* Nome da função:       toPositiveAngle
     * Intenção da função:   Transforma um ângulo de [-PI, PI] para [0, 2PI]
     * Pré-requisitos:       O ângulo deve estar entre [-PI, PI]
     * Efeitos colaterais:   Nenhum
     * Parâmetros:           double : ângulo a ser transformado
     * Retorno:              double : ângulo transformado
     */
    double toPositiveAngle(double angle);

    /* Nome da função:       smallestAngleDiff
     * Intenção da função:   Retorna a menor distância angular entre dois ângulos
     * Pré-requisitos:       Necessitar da diferença entre dois ângulos
     * Efeitos colaterais:   Nenhum
     * Parâmetros:           double : ângulo alvo
     *                       double : ângulo fonte
     * Retorno:              double : distancia ângular entre os dois ângulos
     */
    double smallestAngleDiff(double target, double source);

    /* Nome da função:       to180range
     * Intenção da função:   Transforma um ângulo para o domínio [-PI, PI]
     * Pré-requisitos:       O angulo está num domínio diferente de [-PI, PI]
     * Efeitos colaterais:   Nenhum
     * Parâmetros:           double : ângulo ser transformado
     * Retorno:              double : ângulo transformado
     */
    double to180range(double angle);

    /* Nome da função:       distance
     * Intenção da função:   Retorna a distância entre dois pontos
     * Pré-requisitos:       Nenhum
     * Efeitos colaterais:   Nenhum
     * Parâmetros:           pair<double, double> : coordenadas do primeiro ponto
     *                       pair<double, double> : coordenadas do segundo ponto
     * Retorno:              pair<double, double> : distância entre o ponto "first" e o ponto "second"
     */
    double distance(doublePair first, doublePair second);

    /* Nome da função:       bound
     * Intenção da função:   Transforma o valor x para o domínio [low, high]
     * Pré-requisitos:       Nenhum
     * Efeitos colaterais:   Nenhum
     * Parâmetros:           double : Número a ser transformado
     *                       double : Lower bound da transformação (mínimo valor do domínio)
     *                       double : Upper bound da transformação (máximo valor do domínio)
     * Retorno:              double : Número transformado
     */
    double bound (double x, double low, double high);
};


#endif
