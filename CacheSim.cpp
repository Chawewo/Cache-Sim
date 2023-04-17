 // Created by David T.
 //
 #include <iostream>
 using namespace std;
 // Divide address / line size = frame
 // 
const int l1_latency = 1;
const int l2_latency = 10;
const int l3_latency = 100;
const int l1_line = 1000;
const int l2_line = 6400;
const int l3_line = 10000;
// address of a line is the starting address of the memory
// region which it contains. line size 1KB 
//0x0400 - 0x07ff any access in this range is a hit
struct L1 {
    int address = 0;
}
struct L2{
    int address = 0;
}
struct L3{
    int address = 0;
}
 int main()
 {
    L1 cacheL1[4];
    L2 cacheL2[64];
    L3 cacheL3[256];

    int adress[11] = 
[0x1000,0x1024,0x1599,0x100,0x10245,0x10246,0x1027,0x10247,0x1600,0x1601,0x1700];
    int cpu; // loadaddress which loads val. stored in mem. addr. into the cpu
    int frame; 
    for (int i = 0; i < address.length(); ++i){
        frame = address[i] / l1_Line; // we are looking through L1 to find the address
    }
    return 0;
 }
