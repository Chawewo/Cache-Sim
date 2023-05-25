 /** Created by David T.
  This C++ program simulates a simplified CPU cache hierarchy (L1, L2, and L3) and 
  calculates the total number of CPU cycles required for accessing a series of memory addresses.
  It follows a least recently used (LRU) replacement policy, and accounts for cache misses 
  and hits at each level before resorting to main memory. 
  The final output is the total number of CPU cycles used for all memory accesses.
 */
 #include <iostream> 
 #include <vector>
 using namespace std;
 // Divide address / line size = frame
 // This program simulates 

struct CacheLine {
    int address = 0; // Address of the line
    int size; // Size of the line
    int age = -1; // Age of the line
    CacheLine(int s) : size(s) {} // Constructor taking the size as parameter
};

bool checkstruct(CacheLine &line, int memAddr);
void addStruct(CacheLine &line, int memAddr);
void incrementAge(CacheLine &line);

// Define the latency and line sizes  for L1, L2, L3 caches
const int l1_latency = 1;
const int l2_latency = 10;
const int l3_latency = 100;
const int l1_line = 256;
const int l2_line = 1024;
const int l3_line = 4096;
// address of a line is the starting address of the memory
// region which it contains. line size 1KB 
//0x0400 - 0x07ff any access in this range is a hit

int main() {
    vector<CacheLine> L1(4, CacheLine(l1_line));
    vector<CacheLine> L2(64, CacheLine(l2_line));
    vector<CacheLine> L3(256, CacheLine(l3_line));

    // Define the addresses to be accessed
    vector<int> address = {0x1000,0x1024,0x1599,0x100,0x10245,0x10246,0x1027,0x10247,0x1600,0x1601,0x1700};

    int cycles = 0; // Variable to keep track of the total number of cycles

    // Iterate over each address to be accessed
    for (auto addr : address) {
        bool hit = false; // Variable to check if there was a hit in the cache

        // First, try to find the address in L1 cache
        for (auto &line : L1) {
            if (checkstruct(line, addr)) { // If the address is in L1, increment the cycle count by L1 latency
                cycles += l1_latency;
                hit = true; // Set hit to true
                break;
            }
            incrementAge(line); // If address is not found, increment the age of the line
        }

        // If not found in L1, try to find the address in L2 cache
        if (!hit) {
            for (auto &line : L2) {
                if (checkstruct(line, addr)) {
                    cycles += l1_latency + l2_latency; // If the address is in L2, increment the cycle count by L1 and L2 latencies
                    hit = true; // Set hit to true
                    addStruct(L1[0], addr); // Load the line into L1
                    break;
                }
                incrementAge(line); // If address is not found, increment the age of the line
            }
        }

        // If not found in L2, try to find the address in L3 cache
        if (!hit) {
            for (auto &line : L3) {
                if (checkstruct(line, addr)) {
                    cycles += l1_latency + l2_latency + l3_latency; // If the address is in L3, increment the cycle count by L1, L2 and L3 latencies
                    hit = true; // Set hit to true
                    addStruct(L2[0], addr); // Load the line into L2
                    addStruct(L1[0], addr); // Load the line into L1
                    break;
                }
                incrementAge(line); // If address is not found, increment the age of the line
            }
        }

        // If not found in L3, assume it's in memory
        if (!hit) {
            cycles += 1000; // If the address is in memory, increment the cycle count by a large number
            addStruct(L3[0], addr); // Load the line into L3
            addStruct(L2[0], addr); // Load the line into L2
            addStruct(L1[0], addr); // Load the line into L1
        }
    }

    // Print the total number of cycles
    cout << "Total cycles: " << cycles << endl;
    return 0;
}

// Function to check if a given address is within a cache line
bool checkstruct(CacheLine &line, int memAddr) {
    if (memAddr >= line.address && memAddr < line.address + line.size) { // If the address is within the range of the line
        cout << "Cache Hit!!" << endl;
        line.age = 0; // Reset the age of the line
        return true;
    }
    return false; // If not found, return false
}

// Function to load a given address into a cache line
void addStruct(CacheLine &line, int memAddr) {
    line.address = memAddr - memAddr % line.size; // Set the line address to the start of the memory block
    line.age = 0; // Reset the age of the line
}

// Function to increment the age of a cache line
void incrementAge(CacheLine &line) {
    if (line.address != 0) { // If the line has a valid address
        line.age++; // Increment its age
    }
}