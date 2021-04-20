#include "kernelUtil.h"
#include "memory/heap.h"
#include "scheduling/pit/pit.h"
#include "cstr.h"
#include "gui/window.h"

extern "C" void _start(BootInfo *bootInfo){
    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PIT::setFrequency(65535);

    uint32_t x = 200;
    uint32_t y = 50;
    GUI::Window test(720, 480, x, y, 0x00000000);
    PIT::sleepd(3);
    test.move(x+100, y+100);

    while(true){
        asm("hlt");
    }
}
