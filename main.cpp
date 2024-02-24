#include <iostream>
//#include <opencv2/opencv.hpp>
#include <vector>
#include <fstream>

#include "Server.h"
#include "ThreadsManager.h"
#include "DisplayObserver.h"

#include "Display.h"

int main(int argc , char* argv[])
{
    Server server;

    Display d(640 , 480 , "Turret vision");

    Observer* dO = new DisplayObserver(&d);

    server.attach(dO);

    ThreadsManager tm;


    std::pair<int , Server*> CAMargs;

    CAMargs.first = 0;
    CAMargs.second = &server;


    
    tm.createThread(&server.receiveDataStatic , &CAMargs);


    while(1)
    {
    }

}

/*

*/