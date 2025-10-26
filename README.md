# OS
For operating systems class

# Producer-Consumer with Shared Memory and Semaphores (Process-Level IPC)

## Overview

This project implements a classic **Producer-Consumer** problem using **POSIX semaphores** and **System V shared memory** at the **process level** (not threads). It demonstrates inter-process communication (IPC), synchronization, and mutual exclusion in a Linux/Unix environment.

Two separate programs—`producer` and `consumer`—coordinate through shared memory and semaphores to safely exchange data in a bounded buffer.

---

## Files Included

| File            | Description |
|-----------------|-------------|
| `producer.cpp`  | Producer process that generates and inserts items into the shared buffer. |
| `consumer.cpp`  | Consumer process that retrieves and processes items from the buffer. |
| `common.hpp`    | Shared definitions, constants, and data structures. |
| `shared_mem.cpp`| Shared memory helper functions (create, attach, detach, destroy). |
| `shared_mem.hpp`| Header for shared memory helpers. |
| `README.md`     | This documentation file. |

---

## How to Compile and Run

### Requirements
- Linux/Unix environment
- GCC compiler
- POSIX-compliant system
- Tested in WSL on windows

# Compile
g++ -o producer producer.cpp shared_mem.cpp -pthread -lrt -Wall -Wextra
g++ -o consumer consumer.cpp shared_mem.cpp -pthread -lrt -Wall -Wextra

# Run
./producer
sleep 1
./consumer

Use Ctrl+C to terminate if running continuously

# Key Components

Shared Memory

shmget: Allocates shared memory segment

shmat: Attaches segment to process

shmdt: Detaches segment

shmctl: Cleans up segment

Semaphores

sem_t: Semaphore object

sem_init: Initializes semaphore

sem_wait: Locks access

sem_post: Unlocks access

Used to ensure mutual exclusion and coordinate producer/consumer access.

Mutual Exclusion

Only one process accesses the buffer at a time

Prevents race conditions and data corruption

# Example Output

Produced: 0

Produced: 1

Produced: 2

Produced: 3

Produced: 4

Consumed: 0

Consumed: 1

Consumed: 2

Consumed: 3

Consumed: 4

<img width="920" height="352" alt="image" src="https://github.com/user-attachments/assets/c2094585-68f2-407e-87fe-8f400a4973be" />
