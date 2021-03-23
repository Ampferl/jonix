#include "gdt.h"

__attribute__((aligned(0x1000)))
GDT DefaultGDT = {
        {0,0,0,0x00, 0x00, 0}, //NULL
        {0, 0, 0, 0x9A, 0xA0, 0}, //KernelCode;
        {0, 0, 0, 0x92, 0xA0, 0}, //KernelData;
        {0, 0, 0, 0x00, 0x00, 0}, //UserNull;
        {0, 0, 0, 0x9A, 0xA0, 0}, //UserCode;
        {0, 0, 0, 0x92, 0xA0, 0}  //UserData;
};