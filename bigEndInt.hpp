#pragma once

#include <cstdint>
#include "endian.h/endian.h"


#include <climits>

template <typename T>
T swap_endian(T u) //https://stackoverflow.com/a/4956493
{
    static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}


template<typename T>
struct be{
    T val;

    be (const T& x = 0){
#if BYTE_ORDER == BIG_ENDIAN
        val = x;
#else
        val = swap_endian(x);
#endif
    }

    operator T () const{
#if BYTE_ORDER == BIG_ENDIAN
        return val;
#else
        return swap_endian(val);
#endif
    }

    be& operator++(){
        (*this) = static_cast<T>(*this) + 1;
        return *this;
    }

    be operator++(int){
        be temp = *this;
        ++(*this);
        return temp;
    }

    be& operator--(){
        (*this) = (*this) + 1;
        return *this;
    }

    be operator--(int){
        be temp = *this;
        --(*this);
        return temp;
    }

    be& operator+=(const be& other) {
        *this = *this + other;
        return *this;
    }

    be& operator-=(const be& other) {
        *this = *this - other;
        return *this;
    }

    be& operator*=(const be& other) {
        *this = *this * other;
        return *this;
    }

    be& operator/=(const be& other) {
        *this = *this / other;
        return *this;
    }

    be& operator%=(const be& other) {
        *this = *this % other;
        return *this;
    }

    be& operator&=(const be& other) {
        *this = *this & other;
        return *this;
    }

    be& operator|=(const be& other) {
        *this = *this | other;
        return *this;
    }

    be& operator^=(const be& other) {
        *this = *this ^ other;
        return *this;
    }

    be& operator<<=(const be& other) {
        *this = *this << other;
        return *this;
    }

    be& operator>>=(const be& other) {
        *this = *this >> other;
        return *this;
    }
};