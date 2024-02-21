#include "EventHandler.h"

void EventHandler::handle(std::vector<char> buffer)
{
    //LOCK 

    std::cout << buffer.data() << std::endl;

    //UNLOCK
}