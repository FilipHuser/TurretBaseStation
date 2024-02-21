#include <iostream>

#include "Server.h"
#include "ThreadsManager.h"

//#include <opencv2/opencv.hpp>

int main(int argc , char* argv[])
{
    Server server;

    std::cout << server.sockets.size() << std::endl;    



    return 0;
}


/*
    Server ser;
    ThreadsManager tm;

    tm.createThread(&ser.receiveDataStatic , &ser);
    
    while(1);

    return 0;
*/