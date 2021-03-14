#include "keyboard.h"

void HandleKeyboard(uint8_t scancode){
    char ascii = QWERTYKeyboard::Translate(scancode, false);
    if(ascii != 0){
        GlobalRenderer->PutChar(ascii);
    }
}