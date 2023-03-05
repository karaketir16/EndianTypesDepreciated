#include <iostream>
#include <cassert>
#include <iomanip>
#include "endian.hpp"
#include <sstream>

#include <bit>

using namespace std;

template<typename T>
void printBytes(const T& val){
    T temp = val;
    uint8_t *ptr = reinterpret_cast<decltype(ptr)>(&temp);
    stringstream ss;
    ss << "val is equal to: " << val << "\tBytes as Hex: ";
    ss << hex;

    for (int i = 0; i < sizeof(T); ++i) {
        ss <<"0x";
        ss.fill('0');
        ss.width(2);
        ss << (int)ptr[i] << " ";
    }
    cout << ss.str() << endl;
}

int main(){

    be_int32_t   a = 5;
    le_uint32_t  b = 6;
    int64_t      c = 7;

    assert(a == 5);
    a *= b;
    assert(a == 30);
    a *= 5;
    assert(a == 150);
    a /= c;
    assert(a == 21);

    a = a * c;
    a = a + le_float (be_double (be_int8_t(int(le_int16_t(3)))));

    assert(a == 150);
    a = a / 5;
    assert(a == 30);
    a = a / b;
    assert(a == 5);

    be_int32_t w(3.4);
    assert(w == 3);

    be_int32_t      k;
    le_uint32_t     l;
    int64_t         m;

    k = l = m = 0xAABB;
    assert(k == l && l == m && k == m);

    printBytes(k);
    printBytes(l);
    printBytes(m);


    return 0;
}
