#include <iostream>

#include "Server.h"
#include "ThreadsManager.h"

int main(int argc , char* argv[])
{
    Server ser;
    ThreadsManager tm;

    tm.createThread(&ser.receiveDataStatic , &ser);
    


    while(1);

    return 0;
}