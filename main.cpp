#include <iostream>
#include <mutex>
#include <vector>

#include "Server.h"
#include "ThreadsManager.h"

//#include <opencv2/opencv.hpp>

int main(int argc , char* argv[])
{
    Server server;

    ThreadsManager tm;

    std::pair<int , Server*> CAMargs;

    CAMargs.first = 0;
    CAMargs.second = &server;
    
    tm.createThread(&server.receiveDataStatic , &CAMargs);


    while(1)
    {
        std::cout << server.getBufferFromQueue().data() << std::endl;
    }

    return 0;
}