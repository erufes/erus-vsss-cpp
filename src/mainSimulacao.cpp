/* ###############################################################################################################
 * Projeto: VSSS o Melhor
 * Github: https://github.com/erusbot/VSSS-o-Melhor
 * Autor: ERUS UFES
 * 				e-mail: erus@inf.ufes.br/ vssserus@gmail.com
 * 				site: erus.ufes.br
 * Membros:
 * 			Gabriel Valdino, Lara de Luca, Lorena Bassani, Ricardo Rauta, Victor de Oliveira
 */


#define UsingSimulator

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include "cstdlib"
#include <getopt.h>
#include <string>
//#include <getopt.h>
#include <string>
//#include "generic_player.hpp"
#include "senderCommands.hpp"
#include "senderDebug.hpp"

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
    vsssERUS::TeamPlayer* player1 = new vsssERUS::TeamPlayer(Funcao::Atacante, 0);
    vsssERUS::TeamPlayer* player2 = new vsssERUS::TeamPlayer(Funcao::Goleiro, 1);
    vsssERUS::TeamPlayer* player3 = new vsssERUS::TeamPlayer(Funcao::Defensor, 2);
    vsssERUS::TeamPlayer* team[] = {player1, player2, player3};

    //Cria três enemy
    Enemy* enemyteam[] = {new Enemy(3), new Enemy(4), new Enemy(5)};

    
    //Cria e configura um World
    #ifdef UsingSimulator
        World* mundo = new World(new Campo("ConstrutorCampoSimulador.txt"), team, enemyteam, new vsssERUS::Ball(state.ball.x, state.ball.y));
    #else
        World* mundo = new World(new Campo("tst.txt"), team, enemyteam, new vsssERUS::Ball(0, 0));
    #endif


    while (true)
    {
        #ifdef UsingSimulator
            state = stateReceiver->receiveState(FieldTransformationType::None);

            //Pega Nova posição da Bola no simulador
            mundo->getBall->update_position(Ponto(state.ball.x, state.ball.y));

            //Pega novas posições dos jogadores no simulador
            player1->setPosicao(Ponto(state.teamBlue.at(0).x,state.teamBlue.at(0).y));
            player1->setTheta(state.teamBlue.at(0).angle);

            player2->setPosicao(Ponto(state.teamBlue.at(1).x,state.teamBlue.at(1).y));
            player2->setTheta(state.teamBlue.at(1).angle);

            player3->setPosicao(Ponto(state.teamBlue.at(2).x,state.teamBlue.at(2).y));
            player3->setTheta(state.teamBlue.at(2).angle);

            mundo->getEnemy()[0]->setPosicao(Ponto(state.teamYellow.at(0).x, state.teamYellow.at(0).y));
            mundo->getEnemy()[0]->setTheta(state.teamYellow.at(0).angle);

            mundo->getEnemy()[1]->setPosicao(Ponto(state.teamYellow.at(1).x, state.teamYellow.at(1).y));
            mundo->getEnemy()[1]->setTheta(state.teamYellow.at(1).angle);

            mundo->getEnemy()[2]->setPosicao(Ponto(state.teamYellow.at(2).x, state.teamYellow.at(2).y));
            mundo->getEnemy()[2]->setTheta(state.teamYellow.at(2).angle);


            //Determina para onde mandar os players
            WheelsCommand player1_command = player1->update(state, 0, mundo);
            WheelsCommand player2_command = player2->update(state, 1, mundo);
            WheelsCommand player3_command = player3->update(state, 2, mundo);

            //Envia os comandos para o simulador
            commandsSender->send_commands(player1_command, player2_command, player3_command);
            debugSender->send_debug();
            
        #endif


    }


    return 0;
}


