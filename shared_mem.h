#ifndef SHARED_MEM_H
#define SHARED_MEM_H

#include "common.h"

int create_shared_memory();
SharedMemory* attach_shared_memory(int shmid);
void detach_shared_memory(SharedMemory* shm);
void destroy_shared_memory(int shmid);

#endif
