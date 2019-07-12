#ifndef SENDERDEBUG_H_
#define SENDERDEBUG_H_
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