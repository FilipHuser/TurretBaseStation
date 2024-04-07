#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "BaseStationBuilder.h"
#include "Director.h"

int main(int argc , char* argv[])
{
	uid_t uid = getuid();
	char xdg_runtime_dir[128];
	snprintf(xdg_runtime_dir , sizeof(xdg_runtime_dir) ,"/run/user/%d" , uid); 

	setenv("XDG_RUNTIME_DIR" , xdg_runtime_dir , 1);

    Director d;
    std::unique_ptr<BaseStationBuilder> bsb = std::make_unique<BaseStationBuilder>();

    d.setBuilder(bsb.get());

    d.buildMinimalBaseStation();

    std::unique_ptr<BaseStation> b = bsb->getProduct();

    b->run();

    return 0;
}