#ifndef SENDERCOMMANDS_H_
#define SENDERCOMMANDS_H_

/* Nome do módulo :         senderCommands
 * Ano de criação :         2019/01
 * Descrição do módulo :    Modulo de comunicação com o simulador para envio de comandos
 * Versão :                 1.0
 * Pré-requisitos :         Simulador embutido ao projeto VSS-SDK https://github.com/VSS-SDK
 *                          Interfaces/ICommandSender (VSS-SDK)
 *                          Communications/CommandSender (VSS-SDK)
 * Membros :                Lorena Bassani
 */
#include <Interfaces/ICommandSender.h>
#include <Communications/CommandSender.h>

using namespace vss;

class senderCommands{
    

    public:
        ICommandSender *commandSender;
        senderCommands(){
            this->commandSender = new CommandSender();
        }
        virtual ~senderCommands(){
        }

        /* Nome da função :     send_commands
         * Intenção da função : Enviar comandos ao simulador
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Comandos são eviados ao simulador para movimentar 3 players
         * Parâmetros :         WheelsCommand : Comandos do primeiro jogador
         *                      WheelsCommand : Comandos do segundo jogador
         *                      WheelsCommand : Comandos do terceiro jogador
         * Retorno:             Nenhum
         */
        void send_commands(WheelsCommand player1Command, WheelsCommand player2Command, WheelsCommand player3Command){
            Command command;

            for(int i = 0 ; i < 3 ; i++){
                command.commands.push_back(WheelsCommand(10, -10));
            }

            command.commands[0] = player1Command;
            command.commands[1] = player2Command;
            command.commands[2] = player3Command;

            commandSender->sendCommand(command);
        }

};

#endif