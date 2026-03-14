# Memory Allocation Schemes

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://gcc.gnu.org/)
[![OS Concept](https://img.shields.io/badge/Concept-Operating%20Systems-red.svg)](https://en.wikipedia.org/wiki/Memory_management)

This project implements various memory management strategies used by Operating Systems to allocate processes to memory blocks.

## Schemes Implemented
The program includes four primary memory allocation algorithms:
1. **First Fit:** Allocates the first hole that is big enough.
2. **Best Fit:** Allocates the smallest hole that is big enough, searching the entire list.
3. **Worst Fit:** Allocates the largest hole available to leave the largest possible leftover space.
4. **Next Fit:** Similar to First Fit but starts searching from the location of the last allocation.

## How to Run
To compile and run this program on a Linux/Unix system, use the following commands:

```bash
gcc Memoryalloc.c -o memory_alloc
./memory_alloc


