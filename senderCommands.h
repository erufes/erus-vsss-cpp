#ifndef SENDERCOMMANDS_H_
#define SENDERCOMMANDS_H_
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