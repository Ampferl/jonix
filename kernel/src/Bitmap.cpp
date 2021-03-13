#include "Bitmap.h"

bool Bitmap::operator[](uint64_t index) {
    uint64_t byteIndex = index / 8;
    uint8_t bitIndex = index % 8;
    uint8_t bitIndexer = 0b10000000 >> bitIndex;
    return (Buffer[byteIndex] & bitIndexer) > 0;
}

void Bitmap::Set(uint64_t index, bool value) {
    uint64_t byteIndex = index / 8;
    uint8_t bitIndex = index % 8;
    uint8_t bitIndexer = 0b10000000 >> bitIndex;
    Buffer[byteIndex] &= ~bitIndexer;
    if(value){
        Buffer[byteIndex] |= bitIndexer;
    }
}