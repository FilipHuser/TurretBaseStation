#include <iostream>

#include "Server.h"

int main(int argc , char* argv[])
{
    Server ser;

    while(1)
    {
        ser.receiveData();
    }

    return 0;
}