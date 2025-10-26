#ifndef COMMON_HPP
#define COMMON_HPP

#include <semaphore.h>

constexpr key_t SHM_KEY = 0x1234;
constexpr int BUFFER_SIZE = 5;

struct SharedMemory {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t mutex;
    sem_t empty;
    sem_t full;
};

#endif
