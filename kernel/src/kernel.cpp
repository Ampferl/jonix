#include "kernelUtil.h"

extern "C" void _start(BootInfo *bootInfo){
    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    GlobalRenderer->Println("Kernel Initialized Successfully");

    GlobalRenderer->Clear(0x00FF0000);
    GlobalRenderer->Println("Error!");

    while(true);
}
