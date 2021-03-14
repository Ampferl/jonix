#include "interrupts.h"

__attribute__((interrupt)) void PageFault_Handler(struct interrupt_frame* frame){
    GlobalRenderer->Println("Page fault detected");
    while(true);
}