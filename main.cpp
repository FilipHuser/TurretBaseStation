#include <iostream>
//#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>

#include "Server.h"
#include "ServerDispatcher.h"
#include "ThreadsManager.h"

#include "Display.h"

int main(int argc , char* argv[])
{
    Server server;

    ThreadsManager tm;

    ServerDispatcher sd(&server);

    std::pair<int , Server*> CAMargs;

    CAMargs.first = 0;
    CAMargs.second = &server;
    
    tm.createThread(&server.receiveDataStatic , &CAMargs);
    tm.createThread(&sd.dispatchStatic , &sd);


    Display d(800 , 480, "Turret vision");

    while(1)
    {
        d.show();
    }

}

/*

*/