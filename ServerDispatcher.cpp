#include "ServerDispatcher.h"

void* ServerDispatcher::dispatchStatic(void* context)
{
    return ((ServerDispatcher*)(context))->dispatch();
}

void* ServerDispatcher::dispatch()
{

    while(1)
    {
        std::vector<char> incoming_buffer = this->server->getBufferFromQueue();

        switch(incoming_buffer[0])
        {
            case 'I':
                std::cout << "I" << std::endl;
                break;
        }

    }
}