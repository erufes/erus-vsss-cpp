/* ###############################################################################################################
 * Projeto: VSSS o Melhor
 * Descrição : Este projeto da ERUS procura criar um time de Very Small Size Soccer para competições.
 * Github: https://github.com/erusbot/VSSS-o-Melhor
 * Autor: ERUS UFES
 * 			e-mail: erus@inf.ufes.br / vssserus@gmail.com
 * 			site: http://erus.ufes.br
 * Membros Atuais:
 * 			Gabriel Pietroluongo, Gabriel Valdino, Mayke Wallace, Lara de Luca, Lorena Bassani
 * Membros Antigos:
 *          Ricardo Rauta, Victor de Oliveira
 */


#define UsingSimulator

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include "cstdlib"
#include <getopt.h>
#include <string>
#include "senderCommands.h"
#include "senderDebug.h"
using namespace vss;
#endif

#include "player.h"
#include "teamplayer.h"
#include "campo.h"
#include "world.h"

using namespace vsssERUS;
int main(int argc, char** argv){

    #ifdef UsingSimulator
        //Time padrão Azul
        TeamType simulador = TeamType::Blue;
    
        //Cria um StateReceiver
        IStateReceiver *stateReceiver = new StateReceiver();
        stateReceiver->createSocket();
        State state = stateReceiver->receiveState(FieldTransformationType::None);

        //Cria um CommandsSender
        senderCommands* commandsSender = new senderCommands();
        commandsSender->commandSender->createSocket(simulador);

        //Cria um DebugSender
        senderDebug* debugSender = new senderDebug();
        debugSender->debugSender->createSocket(simulador);

    #endif

    //Cria três vsssERUS::TeamPlayers
    vsssERUS::TeamPlayer* player1 = new vsssERUS::TeamPlayer(Funcao::Goleiro, 0);
    vsssERUS::TeamPlayer* player2 = new vsssERUS::TeamPlayer(Funcao::Atacante, 1);
    vsssERUS::TeamPlayer* team[] = {player1, player2};

    //Cria três enemy
    Enemy* enemyteam[] = {new Enemy(3), new Enemy(4), new Enemy(5)};

    
    //Cria e configura um World
    #ifdef UsingSimulator
        World* mundo = new World(new Campo((char*)"ConstrutorCampoSimulador.txt"), team, enemyteam, new vsssERUS::Ball(state.ball.x, state.ball.y));
        mundo->getCampo()->setLado(Campo::Lado::Esquerda);
    #else
        World* mundo = new World(new Campo("tst.txt"), team, enemyteam, new vsssERUS::Ball(0, 0));
    #endif


    while (true)
    {
        #ifdef UsingSimulator
            state = stateReceiver->receiveState(FieldTransformationType::None);

            //Pega Nova posição da Bola no simulador
            mundo->getBall()->updatePosition(Ponto(state.ball.x, state.ball.y));

            //Pega novas posições dos jogadores no simulador
            player1->updatePosition(Ponto(state.teamBlue.at(0).x,state.teamBlue.at(0).y));
            player1->setTheta(state.teamBlue.at(0).angle);

            mundo->getEnemy()[0]->updatePosition(Ponto(state.teamYellow.at(0).x, state.teamYellow.at(0).y));
            mundo->getEnemy()[0]->setTheta(state.teamYellow.at(0).angle);

            mundo->getEnemy()[1]->updatePosition(Ponto(state.teamYellow.at(1).x, state.teamYellow.at(1).y));
            mundo->getEnemy()[1]->setTheta(state.teamYellow.at(1).angle);

            mundo->getEnemy()[2]->updatePosition(Ponto(state.teamYellow.at(2).x, state.teamYellow.at(2).y));
            mundo->getEnemy()[2]->setTheta(state.teamYellow.at(2).angle);


            //Determina para onde mandar os players
            WheelsCommand player1_command = player1->update(state, 0, mundo);
            WheelsCommand player2_command = player2->update(state, 1, mundo);
            WheelsCommand player3_command;
            player3_command.leftVel = player3_command.rightVel = 0;

            // cout << "Roda 1: " << player1_command.leftVel << "Roda 2: " << player1_command.rightVel << endl;
            //Envia os comandos para o simulador
            commandsSender->send_commands(player1_command, player2_command, player3_command);
            //debugSender->send_debug();
        #endif
    }
    return 0;
}


