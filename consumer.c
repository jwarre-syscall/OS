#include "shared_mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    SharedMemory* shm = attach_shared_memory(shmid);

    for (int i = 0; i < 10; ++i) {
        sem_wait(&shm->full);
        sem_wait(&shm->mutex);

        int item = shm->buffer[shm->out];
        printf("Consumed: %d\n", item);
        shm->out = (shm->out + 1) % BUFFER_SIZE;

        sem_post(&shm->mutex);
        sem_post(&shm->empty);

        sleep(2);
    }

    detach_shared_memory(shm);
    destroy_shared_memory(shmid);
    return 0;
}
