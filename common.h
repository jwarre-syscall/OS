#ifndef COMMON_H
#define COMMON_H

#include <semaphore.h>
#include <sys/types.h>

#define SHM_KEY 0x1234
#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t mutex;
    sem_t empty;
    sem_t full;
} SharedMemory;

#endif
