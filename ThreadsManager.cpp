#include "ThreadsManager.h"

void ThreadsManager::createThread(void* (*threadFunction)(void*) , void* arg)
{
    pthread_t thread;

    if((pthread_create(&thread , nullptr , threadFunction , arg)) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    };

    this->threads.push_back(thread);
}

void ThreadsManager::joinAllThreads()
{
    for (auto& thread : threads) 
    {
        if (pthread_join(thread, nullptr) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }
}