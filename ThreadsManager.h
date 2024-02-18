#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include <vector>
#include <pthread.h>
#include <stdio.h>
#include <cstdlib>

class ThreadsManager{
public:
    ThreadsManager() = default;
    void createThread(void* (*threadFunction)(void*) , void* arg);
    void joinAllThreads();
private:
    std::vector<pthread_t> threads;
};

#endif //THREAD_MANAGER_H