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
        usleep(5000);

        switch(incoming_buffer[0])
        {
            case 'I':
                addToImgBuffer(incoming_buffer);
                break;
        }

    }
}


void ServerDispatcher::addToImgBuffer(std::vector<char> chunk)
{
    this->img_buffer.insert(this->img_buffer.end() , chunk.begin() + 2 , chunk.end());

    //std::cout << this->img_buffer.size() << std::endl;

    if (this->img_buffer.size() >= 1152000)
    {
    }
}