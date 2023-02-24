#include <iostream>
#include  <iomanip>

#include "endian.hpp"

using namespace std;

int main(){

    be_int32_t x = 5;
    char *xp = reinterpret_cast<char*>(&x);
    for(size_t i = 0; i < sizeof(x); i++){
        cout << "0x" << setfill('0') << setw(2) << hex << static_cast<int>(xp[i]) << " ";
    }
    cout << endl;
    //output: 0x00 0x00 0x00 0x05

    le_int32_t y = 5;
    char *yp = reinterpret_cast<char*>(&y);
    for(size_t i = 0; i < sizeof(y); i++){
        cout << "0x" << setfill('0') << setw(2) << hex << static_cast<int>(yp[i]) << " ";
    }
    cout << endl;
    //output: 0x05 0x00 0x00 0x00

    return 0;
}
