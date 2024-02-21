#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <iostream>
#include <mutex>

class SharedData {
public:
    SharedData() = default;

    void passData(char* buffer) {
        std::unique_lock<std::mutex> lock(this->sharedData_mutex);


        std::cout << buffer << std::endl;
    }



private:
    std::mutex sharedData_mutex;
};

#endif //SHARED_DATA_H