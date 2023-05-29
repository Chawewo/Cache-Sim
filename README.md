# Cache-Sim
This project is a C++ program simulating a simplified CPU cache hierarchy (L1, L2, and L3) and calculates the total number of CPU cycles required for accessing a series of memory addresses. The cache hierarchy follows a Least Recently Used (LRU) replacement policy. The simulator accounts for cache misses and hits at each level before resorting to main memory. The final output is the total number of CPU cycles used for all memory accesses.

# Features
Simulation of L1, L2, and L3 cache layers
LRU replacement policy
Calculation of total CPU cycles needed for memory access
# Prerequisites
A modern C++ compiler (e.g., GCC, Clang) that supports C++11 or later.
# Installation
Clone the repository or download the code.
No additional libraries or packages are needed, the standard library is sufficient.
# Usage
Compile the program using a C++ compiler. For instance, using g++: g++ main.cpp -o cache_simulator
Run the resulting executable: ./cache_simulator
The simulator will execute a series of predefined memory accesses and compute the total number of CPU cycles required to process all of these accesses, respecting the hierarchical nature of CPU caches and their respective latencies.

# Functionality
The program includes the following functions:

bool checkstruct(CacheLine &line, int memAddr): Checks if a given address is within a cache line.
void addStruct(CacheLine &line, int memAddr): Loads a given address into a cache line.
void incrementAge(CacheLine &line): Increments the age of a cache line.
