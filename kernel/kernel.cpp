#include "kernelUtil.h"
#include "memory/heap.h"
#include "gui/window.h"
#include "scheduling/pit/pit.h"
#include "cstr.h"

extern "C" void _start(BootInfo *bootInfo){
    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PIT::setFrequency(65535);

    GUI::Window window1 = GUI::Window(200, 100, 0x00FFFFFF);
    windows[0] = &window1;
    windows[0]->create();

    while(true){
        asm("hlt");
    }
}
