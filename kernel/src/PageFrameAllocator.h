#pragma once
#include <stdint.h>
#include "memory.h"
#include "Bitmap.h"
#include "efiMemory.h"

class PageFrameAllocator{
    public:
        void ReadEFIMemoryMap(EFI_MEMORY_DESCRIPTOR* mMap, size_t mMapSize, size_t mMapDescSize);
        Bitmap PageBitmap;

    private:
        void InitBitmap(size_t bitmapSize, void* bufferAddress);
};