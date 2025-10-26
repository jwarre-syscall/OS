#include "shared_mem.hpp"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <cstdlib>

int create_shared_memory() {
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    return shmid;
}

SharedMemory* attach_shared_memory(int shmid) {
    void* addr = shmat(shmid, nullptr, 0);
    if (addr == (void*)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return static_cast<SharedMemory*>(addr);
}

void detach_shared_memory(SharedMemory* shm) {
    shmdt(shm);
}

void destroy_shared_memory(int shmid) {
    shmctl(shmid, IPC_RMID, nullptr);
}
