#include "shared_mem.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    SharedMemory* shm = attach_shared_memory(shmid);

    for (int i = 0; i < 10; ++i) {
        sem_wait(&shm->full);
        sem_wait(&shm->mutex);

        int item = shm->buffer[shm->out];
        std::cout << "Consumed: " << item << std::endl;
        shm->out = (shm->out + 1) % BUFFER_SIZE;

        sem_post(&shm->mutex);
        sem_post(&shm->empty);

        sleep(2);
    }

    detach_shared_memory(shm);
    destroy_shared_memory(shmid);
    return 0;
}
