# Philosophers Project

## Overview
The **Philosophers** project is a simulation of the classic **Dining Philosophers Problem**. It demonstrates synchronization issues in concurrent programming and how to solve them using threads, mutexes, and semaphores. The goal is to prevent deadlocks and ensure all philosophers can eat without starving.

---

## Problem Description
- **Philosophers** sit around a circular table.
- Each philosopher **alternates between thinking and eating**.
- To eat, a philosopher needs **two forks** (one on their left and one on their right).
- Forks are shared resources, and access must be synchronized to avoid conflicts.

---

## Requirements
- The program must handle **multiple philosophers**.
- Each philosopher is represented by a **thread**.
- Forks are represented by **mutexes** or **semaphores**.
- The program must avoid **deadlocks** and **starvation**.

---

## How It Works
1. **Initialization**:
   - The program takes the following arguments:
     - `number_of_philosophers`
     - `time_to_die` (in milliseconds)
     - `time_to_eat` (in milliseconds)
     - `time_to_sleep` (in milliseconds)
     - `[number_of_times_each_philosopher_must_eat]` (optional)
   - Forks (mutexes) and philosophers (threads) are initialized.

2. **Simulation**:
   - Each philosopher alternates between **thinking** and **eating**.
   - To eat, a philosopher must acquire **two forks**.
   - After eating, the philosopher releases the forks and starts **sleeping**.

3. **Termination**:
   - The simulation ends if:
     - A philosopher **starves** (does not eat within `time_to_die`).
     - All philosophers have eaten the required number of times (if specified).

---

## Key Concepts
- **Threads**: Each philosopher runs in a separate thread.
- **Mutexes**: Used to represent forks and ensure exclusive access.
- **Deadlock Prevention**: Implemented by enforcing an order in which forks are picked up.
- **Starvation Prevention**: Ensured by fair scheduling and timeouts.

---

## Usage
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd philosophers
