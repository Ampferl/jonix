#include "kernelUtil.h"
#include "memory/heap.h"

extern "C" void _start(BootInfo *bootInfo){
    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    GlobalRenderer->Println("Kernel Initialized Successfully");

    GlobalRenderer->Println(to_hex_string((uint64_t)bootInfo->rsdp));

    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x100)));
    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x100)));
    GlobalRenderer->Println(to_hex_string((uint64_t)malloc(0x100)));

    while(true);
}
