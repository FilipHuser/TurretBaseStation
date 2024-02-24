#include "ServerDispatcher.h"

void* ServerDispatcher::dispatchStatic(void* context)
{
    return ((ServerDispatcher*)(context))->dispatch();
}

void* ServerDispatcher::dispatch()
{

    while(1)
    {
    }
}