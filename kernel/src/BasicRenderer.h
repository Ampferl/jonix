#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "PSF1Font.h"

class BasicRenderer{
    public:
        Point CursorPosition;
        void Print(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, const char* str);
        void putChar(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, char chr, unsigned int xOff, unsigned int yOff);
};