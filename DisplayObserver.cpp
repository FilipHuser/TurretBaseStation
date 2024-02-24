#include "DisplayObserver.h"

void DisplayObserver::update(Subject* subject)
{
    if (Server* server = dynamic_cast<Server*>(subject))
    {
        this->display->refreshImgFrame(server->img_buffer);
    }
}