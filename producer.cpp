#include "shared_mem.hpp"
#include <iostream>
#include <unistd.h>

int main() {
    int shmid = create_shared_memory();
    SharedMemory* shm = attach_shared_memory(shmid);

    sem_init(&shm->mutex, 1, 1);
    sem_init(&shm->empty, 1, BUFFER_SIZE);
    sem_init(&shm->full, 1, 0);

    shm->in = 0;
    shm->out = 0;

    for (int i = 0; i < 10; ++i) {
        sem_wait(&shm->empty);
        sem_wait(&shm->mutex);

        shm->buffer[shm->in] = i;
        std::cout << "Produced: " << i << std::endl;
        shm->in = (shm->in + 1) % BUFFER_SIZE;

        sem_post(&shm->mutex);
        sem_post(&shm->full);

        sleep(1);
    }

    detach_shared_memory(shm);
    return 0;
}
