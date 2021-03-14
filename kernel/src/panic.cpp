#include "panic.h"
#include "BasicRenderer.h"

void Panic(const char* panicMessage){
    GlobalRenderer->Clear(0x00FF0000);
    GlobalRenderer->CursorPosition = {0, 0};
    GlobalRenderer->Color = 0x00000000;
    GlobalRenderer->Println("Kernel Panic");
    GlobalRenderer->Next();
    GlobalRenderer->Println(panicMessage);
}