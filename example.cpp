#include <iostream>
#include  <iomanip>

//#include "endian.hpp"
#include "bigEndInt.hpp"

using namespace std;
typedef be<int32_t> QQ;


int testF(int x){
    return x*x;
}

int main(){

    QQ a = 5;
    QQ b = 6;

    a *= b;
    a *= 5;

    cout << a / 2 << endl;

    cout << testF(b) << endl;

    return 0;
}
