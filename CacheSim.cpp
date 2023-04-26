 // Created by David T.
 //
 #include <iostream> 
 using namespace std;
 // Divide address / line size = frame
 // This program simulates 
const int l1_latency = 1;
const int l2_latency = 10;
const int l3_latency = 100;
const int l1_line = 256;
const int l2_line = 1024;
const int l3_line = 4096;
int CPU;
// address of a line is the starting address of the memory
// region which it contains. line size 1KB 
//0x0400 - 0x07ff any access in this range is a hit
struct L1 {
    int address = 0;
    int size = 256;
    int age = -1;
}
struct L2{
    int address = 0;
    int size = 1024;
    int age = -1;
}
struct L3{
    int address = 0;
    int size = 4096;
    int age = -1
}
 int main()
 { 
    L1 cacheL1[4];
    L2 cacheL2[64];
    L3 cacheL3[256];

    int address[11] = 
[0x1000,0x1024,0x1599,0x100,0x10245,0x10246,0x1027,0x10247,0x1600,0x1601,0x1700];
    int cpu; // loadaddress which loads val. stored in mem. addr. into the cpu
    double frame; 
    bool hit = false;
    int cycles = 0;
    int finalval = 0;
    // we are searching in L1 right now
    for (int i = 0; i < address.length(); ++i){
        for(int k = 0; k < 4; ++k)
        hit = false;
     // we are looking through L1 to find the address
        hit = checkstruct(cacheL1[k],address[i]);
        if(hit = true)
        {
        cycles += 1;
        break;
        }
        else if (cacheL1[k].address == 0)
        {
            addStruct(cacheL1[k], address[i]);
        }
        else
        {
            for (int y = 0; y < 64; ++y)
            {
                hit = false; // we are now looking through L2 to find the address
                checkstruct(cacheL2[y],address[i]);
                if
            }
        }
        
    }
    return 0;
 }

bool checkstruct(struct cache, int memAddr)
{ // Does the memory value exist in these?
    int maxAddress = cache.address + cache.size;
    bool cacheHit = false;
    if(memAddr > cache.address && memAddr < maxAddress)
    {
        cout << "Cache Hit!!" << endl;
        cacheHit = true;
        return cacheHit;
    }
    else return cacheHit;

}
void addStruct(struct &cache, int memAddr)
{
    if(cache.address == 0){
        //This means that there is currently no address associated in this struct
        cache.address = memAddr;
        cache.age = 0;
    else{
        cout << "There is already a number there" << endl;
        return;
    }
    }
}
void loadaddress(int value)
{
    CPU = value;
}
void incrementAge(struct &cache){
    
}