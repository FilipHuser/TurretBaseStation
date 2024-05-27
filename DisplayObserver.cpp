#include "DisplayObserver.h"

void DisplayObserver::update(Subject* subject)
{
    if (Display* d = dynamic_cast<Display*>(subject))
    {
        server->sendData("SET:C:QL" , 0 , 2);
    }
}
