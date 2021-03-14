#include "kernelUtil.h"

extern "C" void _start(BootInfo *bootInfo){

    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    BasicRenderer newRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

    memset(bootInfo->framebuffer->BaseAddress, 0, bootInfo->framebuffer->BufferSize);

    pageTableManager->MapMemory((void*)0x600000000, (void*)0x8000);
    uint64_t* test = (uint64_t*)0x600000000;
    *test = 26;

    newRenderer.Print(to_string(*test));

    return ;
}
