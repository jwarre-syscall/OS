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
| `Makefile`      | Automates compilation of producer and consumer binaries. |
| `run.sh`        | Script to launch producer and consumer processes. |
| `README.md`     | This documentation file. |

---

## How to Compile and Run

### Requirements
- Linux/Unix environment
- GCC compiler
- POSIX-compliant system

# Compilation
```bash
make

# Execution
./producer &
sleep 1
./consumer

# Example Output
Produced: 0
Consumed: 0
Produced: 1
Produced: 2
Consumed: 1
Consumed: 2
...

