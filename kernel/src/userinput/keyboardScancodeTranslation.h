#pragma once
#include <stdint.h>

namespace QWERTYKeyboard{
    extern const char ASCIITable[];
    char Translate(uint8_t scancode, bool uppercase);
}