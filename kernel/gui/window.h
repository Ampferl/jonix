#pragma once
#include "../memory/heap.h"
#include <stdint.h>

namespace GUI{
    class Window{

        public:
            uint32_t* windowBuffer = new uint32_t[720 * 480];
            uint32_t width = 720;
            uint32_t height = 480;
            uint32_t posX = 0;
            uint32_t posY = 0;
            uint32_t color = 0x00000000;
            void saveBackground();
            void loadBackground();
            void drawWindow();
            void move(uint32_t x, uint32_t y);
            void create();
            Window(uint32_t posX, uint32_t posY, uint32_t color);
            ~Window();

    };
}

extern GUI::Window* windows[10];