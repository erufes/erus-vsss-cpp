#ifndef SENDERDEBUG_H_
#define SENDERDEBUG_H_
/* Nome do módulo :         senderDebug
 * Ano de criação :         2019/01
 * Descrição do módulo :    Modulo de comunicação com o simulador para envio de debug
 * Versão :                 1.0
 * Pré-requisitos :         Simulador embutido ao projeto VSS-SDK https://github.com/VSS-SDK
 *                          Interfaces/IDebugSender (VSS-SDK)
 *                          Communications/DebugSender (VSS-SDK)
 * Membros :                Lorena Bassani
 */

#include <Interfaces/IDebugSender.h>
#include <Communications/DebugSender.h>

using namespace vss;

class senderDebug{
   

    public:
        IDebugSender* debugSender;
        senderDebug(){
            this->debugSender = new DebugSender();
        }
        virtual ~senderDebug(){
        }

        /* Nome da função :     send_debug
         * Intenção da função : Enviar debug ao simulador
         * Pré-requisitos :     Nenhum
         * Efeitos colaterais : Pontos de debug são enviados ao simulador
         * Parâmetros :         Nenhum
         * Retorno:             Nenhum
         */
        void send_debug(){
            vss::Debug debug;

            for(unsigned int i = 0 ; i < 3 ; i++){
                debug.stepPoints.push_back(Point(85 + rand()%20, 65 + rand()%20));
            }

            for(unsigned int i = 0 ; i < 3 ; i++){
                debug.finalPoses.push_back(Pose(85 + rand()%20, 65 + rand()%20, rand()%20));
            }

            for(unsigned int i = 0 ; i < 3 ; i++){
                vss::Path path;
                path.points.push_back(Point(85, 65));
                path.points.push_back(Point(85 + rand()%20, 65 + rand()%20));
            }

            debugSender->sendDebug(debug);
        }
};

#endif