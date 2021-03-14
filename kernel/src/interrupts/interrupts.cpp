#include "interrupts.h"
#include "../panic.h"

__attribute__((interrupt)) void PageFault_Handler(struct interrupt_frame* frame){
    Panic("Page fault detected");
    while(true);
}

__attribute__((interrupt)) void DoubleFault_Handler(struct interrupt_frame* frame){
    Panic("Double fault detected");
    while(true);
}

__attribute__((interrupt)) void GPFault_Handler(struct interrupt_frame* frame){
    Panic("General Protection fault detected");
    while(true);
}
