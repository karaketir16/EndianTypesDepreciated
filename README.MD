# C++ Data Type with Endianness

Create integers and floating point numbers with specific endiannes.

These types can be used as normal C++ number types. I mean, supports for arithmetic and assignment operators. Can be converted to each others(and default types) with implicit conversions.

## Big endian types
```
be_int8_t
be_int16_t
be_int32_t
be_int64_t

be_uint8_t
be_uint16_t
be_uint32_t
be_uint64_t

be_float
be_double
```

## Little endian types
```
le_int8_t
le_int16_t
le_int32_t
le_int64_t

le_uint8_t
le_uint16_t
le_uint32_t
le_uint64_t

le_float
le_double
```
### Notes

This repository is not well tested. If you face with any problem, please open a issue.

### Example
```c++
be_int32_t      k;
le_uint32_t     l;
int64_t         m;

k = l = m = 0xAABB;
assert(k == l && l == m && k == m);
```

```c++ 
val is equal to: 43707  Bytes as Hex: 0x00 0x00 0xaa 0xbb
val is equal to: 43707  Bytes as Hex: 0xbb 0xaa 0x00 0x00
val is equal to: 43707  Bytes as Hex: 0xbb 0xaa 0x00 0x00 0x00 0x00 0x00 0x00
```