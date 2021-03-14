#include "interrupts.h"
#include "../panic.h"

__attribute__((interrupt)) void PageFault_Handler(struct interrupt_frame* frame){
    Panic("Page fault detected");
    while(true);
}