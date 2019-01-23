/* Nome do m�dulo: mainSimulacao
 * Ano de cria��o: 2019/01
 * Descri��o do m�dulo: Classe que executa uma simulação
 * Vers�o: 1.0
 * Pr�-requisitos: VSS-Simulator instalado no computador
 * Membros: Lorena BBassani
*/

#define UsingSimulator

#ifdef UsingSimulator
#include <Communications/StateReceiver.h>
#include "cstdlib"
#include <getopt.h>
#include <string>
#include <getopt.h>
#include <string>
#include "generic_player.hpp"
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

    //Cria uma bola
    #ifdef UsingSimulator
        vsssERUS::Ball* ball = new vsssERUS::Ball(state.ball.x, state.ball.y);    
    #else
        vsssERUS::Ball* ball = new vsssERUS::Ball(0, 0);
    #endif

    //Cria um Campo
    #ifdef UsingSimulator
        Campo* campo = new Campo("ConstrutorCampoSimulador.txt");
    #else
        Campo* campo = new Campo("teste.txt");
    #endif

    //Cria e configura um World
    World* mundo = new World(campo, team, enemyteam, ball);


    while (true)
    {
        #ifdef UsingSimulator
            state = stateReceiver->receiveState(FieldTransformationType::None);

            WheelsCommand player1_command = player1->update(state, 0);
            WheelsCommand player2_command = player2->update(state, 1);
            WheelsCommand player3_command = player3->update(state, 2);

            commandsSender->send_commands(player1_command, player2_command, player3_command);
            debugSender->send_debug();
        #endif
    }


    return 0;
}


