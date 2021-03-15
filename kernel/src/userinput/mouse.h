#pragma once
#include "../IO.h"
#include "../math.h"
#include "../BasicRenderer.h"

#define PS2LButton 0b00000001
#define PS2MButton 0b00000010
#define PS2RButton 0b00000100

#define PS2XSign 0b00010000
#define PS2YSign 0b00100000
#define PS2XOverflow 0b01000000
#define PS2YOverflow 0b10000000

extern uint8_t MousePointer[];

void HandlePS2Mouse(uint8_t data);
void InitPS2Mouse();
void ProcessMousePacket();
extern Point MousePosition;