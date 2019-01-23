#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

#include <Communications/StateReceiver.h>
#include <Communications/CommandSender.h>
#include <math.h>
#include <iostream>
#include "utils.hpp"


/**
 * @brief Guarda a lógica de funcionamento de um jogador
 * 
 */
class GenericPlayer {
    private:
        vss::TeamType _teamType;


    public:

        GenericPlayer(vss::TeamType type) {
            this->_teamType = type;
        }

        /**
         * @brief Função chamada a cada atualização com informações novas
         * 
         * @param state Estado atual do jogo
         * @param index Indice do robo que se deseja atualizar 
         * @return vss::WheelsCommand Comandos para as rodas do robo que se deseja atualizar
         */
        vss::WheelsCommand update(vss::State state, int index) {
            Utils::Posture objective = defineObjective(state, index);
            return motionControl(state, objective, index);
        }

        /**
         * @brief Define a postura final que se deseja chegar na iteração atual
         * 
         * @param index Indice do robo que se deseja atualizar 
         * @return Posture Posiçãoque se deseja adquirir
         */
        virtual Utils::Posture defineObjective(vss::State, int index) = 0;

        /**
         * @brief Traduz o objetivo desejado em velocidade das rodas utilizando o algoritmo Motion Control presente 
         * no livro Autonomous Mobile Robots, Siegwart
         * 
         * @param state Situação de jogo atual
         * @param objective Posição que se deseja chegar
         * @param index Indice do robo que se deseja atualizar
         * @return vss::WheelsCommand Comandos para as rodas do robo que se deseja atualizar
         */
        virtual vss::WheelsCommand motionControl(vss::State state, Utils::Posture objective, int index) = 0;

};

#endif