#include "ServerObserver.h"

void ServerObserver::update(Subject* subject)
{
    if (Server* server = dynamic_cast<Server*>(subject))
    {
        this->display->refreshImgFrame(server->getCamBuffer());
    }
}