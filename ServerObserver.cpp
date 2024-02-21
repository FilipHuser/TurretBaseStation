#include "ServerObserver.h"

void ServerObserver::update(Subject* subject)
{
    if(Server* server = dynamic_cast<Server*>(subject))
    {
        std::cout << "buffer: " << server->getBufferFromQueue().data() << std::endl;


        //this->eventHandler->handle();
    }
}