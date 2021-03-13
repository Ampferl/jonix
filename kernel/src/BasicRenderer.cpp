#include "BasicRenderer.h"

void BasicRenderer::Print(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, const char* str){
    char* chr = (char*)str;
    while(*chr != 0){
        putChar(framebuffer, psf1Font, color, *chr, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X+=8;
        if(CursorPosition.X + 8 > framebuffer->Width){
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
        chr++;
    }
}

void BasicRenderer::putChar(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, char chr, unsigned int xOff, unsigned int yOff){
    unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
    char* fontPtr = (char*)psf1Font->glyphBuffer + (chr * psf1Font->psf1_Header->charsize);
    for(unsigned long y = yOff; y < yOff + 16; y++){
        for(unsigned long x = xOff; x < xOff+8; x++){
            if((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                *(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanline)) = color;
            }
        }
        fontPtr++;
    }
}