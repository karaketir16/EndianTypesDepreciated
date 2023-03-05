#pragma once

#include <stdint.h>
#include <endian.h/endian.h>

namespace _endian_ {

bool is_little_endian(){
#ifdef BYTE_ORDER
    return BYTE_ORDER == LITTLE_ENDIAN;
#else
    int x = 1;
    char *c = reinterpret_cast<char*>(&x);
    return c[0];
#endif
}


enum class Endian{
    eBIG_ENDIAN,
    eLITTLE_ENDIAN
};

bool IsSameEndian(Endian e){
    static const bool is_le = is_little_endian(); 
    switch (e)
    {
    case Endian::eBIG_ENDIAN:
        return !is_le;
        break;
    case Endian::eLITTLE_ENDIAN:
        return is_le;
        break;
    }
    return false;
};


template<typename T, Endian e>
struct _E_Base{

    _E_Base(const T& x = 0){
        if(IsSameEndian(e)){
            this->val = x;
        } else {
            this->val = _swapOrder(x);
        }
    }

    template<typename otherType>    
    operator otherType() const{
        if(IsSameEndian(e)){
            return this->val;
        } else {
            return _swapOrder(this->val);
        }
    }

    _E_Base& operator++(){
        (*this) = static_cast<T>(*this) + 1;
        return *this;
    }

    _E_Base operator++(int){
        _E_Base temp = *this;
        ++(*this);
        return temp;
    }

    _E_Base& operator--(){
        (*this) = (*this) + 1;
        return *this;
    }

    _E_Base operator--(int){
        _E_Base temp = *this;
        --(*this);
        return temp;
    }

    _E_Base& operator+=(const _E_Base& other) {
        *this = *this + other;
        return *this;
    }

    _E_Base& operator-=(const _E_Base& other) {
        *this = *this - other;
        return *this;
    }

    _E_Base& operator*=(const _E_Base& other) {
        *this = *this * other;
        return *this;
    }

    _E_Base& operator/=(const _E_Base& other) {
        *this = *this / other;
        return *this;
    }

    _E_Base& operator%=(const _E_Base& other) {
        *this = *this % other;
        return *this;
    }

    _E_Base& operator&=(const _E_Base& other) {
        *this = *this & other;
        return *this;
    }

    _E_Base& operator|=(const _E_Base& other) {
        *this = *this | other;
        return *this;
    }

    _E_Base& operator^=(const _E_Base& other) {
        *this = *this ^ other;
        return *this;
    }

    _E_Base& operator<<=(const _E_Base& other) {
        *this = *this << other;
        return *this;
    }

    _E_Base& operator>>=(const _E_Base& other) {
        *this = *this >> other;
        return *this;
    }

protected:
    T val;
};


#define _CREATE_ENDIAN_TYPE(x) \
typedef _endian_::_E_Base<x, _endian_::Endian::eBIG_ENDIAN> be_##x;\
typedef _endian_::_E_Base<x, _endian_::Endian::eLITTLE_ENDIAN> le_##x;


}

_CREATE_ENDIAN_TYPE(int8_t)
_CREATE_ENDIAN_TYPE(int16_t)
_CREATE_ENDIAN_TYPE(int32_t)
_CREATE_ENDIAN_TYPE(int64_t)

_CREATE_ENDIAN_TYPE(uint8_t)
_CREATE_ENDIAN_TYPE(uint16_t)
_CREATE_ENDIAN_TYPE(uint32_t)
_CREATE_ENDIAN_TYPE(uint64_t)

_CREATE_ENDIAN_TYPE(float)
_CREATE_ENDIAN_TYPE(double)