#ifndef SHARED_MEM_HPP
#define SHARED_MEM_HPP

#include "common.hpp"

int create_shared_memory();
SharedMemory* attach_shared_memory(int shmid);
void detach_shared_memory(SharedMemory* shm);
void destroy_shared_memory(int shmid);

#endif
