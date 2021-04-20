#pragma once
#include <stdint.h>

namespace GUI{
    class Window{
        private:
            uint32_t* windowBuffer;
            uint32_t width = 0;
            uint32_t height = 0;
            uint32_t posX = 0;
            uint32_t posY = 0;
            uint32_t color = 0x00000000;
            void saveBackground();
            void loadBackground();
            void drawWindow();

        public:
            Window(uint32_t width, uint32_t height, uint32_t posX, uint32_t posY, uint32_t color);
            ~Window();
            void move(uint32_t x, uint32_t y);

    };
}