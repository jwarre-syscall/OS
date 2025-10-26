#include "shared_mem.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int create_shared_memory() {
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    return shmid;
}

SharedMemory* attach_shared_memory(int shmid) {
    SharedMemory* shm = (SharedMemory*)shmat(shmid, NULL, 0);
    if (shm == (void*)-1) {
        perror("shmat");
        exit(1);
    }
    return shm;
}

void detach_shared_memory(SharedMemory* shm) {
    shmdt(shm);
}

void destroy_shared_memory(int shmid) {
    shmctl(shmid, IPC_RMID, NULL);
}
