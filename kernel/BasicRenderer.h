#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "PSF1Font.h"
#include <stdint.h>

class BasicRenderer{
    public:
        BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font);
        Point CursorPosition;
        Framebuffer* TargetFramebuffer;
        PSF1_FONT* PSF1_Font;
        unsigned int Color;
        unsigned int ClearColor;
        uint32_t MouseCursorBuffer[16 * 16];
        uint32_t MouseCursorBufferAfter[16 * 16];
        bool MouseDrawn;
        void Print(const char* str);
        void Println(const char* str);
        void Clear();
        void ClearChar();
        void ClearMouseCursor(uint8_t* mouseCursor, Point position);
        void Next();
        void PutChar(char chr, unsigned int xOff, unsigned int yOff);
        void PutChar(char chr);
        void PutPix(uint32_t x, uint32_t y, uint32_t color);
        void DrawRectangle(uint32_t width, uint32_t height, uint32_t x, uint32_t y, uint32_t color);
        void DrawCircle(uint32_t radius, uint32_t x, uint32_t y, uint32_t color);
        uint32_t GetPix(uint32_t x, uint32_t y);
        void DrawOverlayMouseCursor(uint8_t* mouseCursor, Point position, uint32_t color);
};

extern BasicRenderer* GlobalRenderer;