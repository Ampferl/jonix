#include "BasicRenderer.h"

BasicRenderer* GlobalRenderer;

BasicRenderer::BasicRenderer(Framebuffer* targetFramebuffer, PSF1_FONT* psf1_Font){
    TargetFramebuffer = targetFramebuffer;
    PSF1_Font = psf1_Font;
    Color = 0xFFFFFFFF;
    CursorPosition = {0,0};
}

void BasicRenderer::Print(const char* str){
    char* chr = (char*)str;
    while(*chr != 0){
        PutChar(*chr, CursorPosition.X, CursorPosition.Y);
        CursorPosition.X+=8;
        if(CursorPosition.X + 8 > TargetFramebuffer->Width){
            CursorPosition.X = 0;
            CursorPosition.Y += 16;
        }
        chr++;
    }
}

void BasicRenderer::Next(){
    CursorPosition.X = 0;
    CursorPosition.Y += 16;
}

void BasicRenderer::Println(const char* str){
    Print(str);
    Next();
}

void BasicRenderer::Clear(uint32_t color){
    uint64_t fbBase = (uint64_t)TargetFramebuffer->BaseAddress;
    uint64_t bytesPerScanline = TargetFramebuffer->PixelsPerScanline * 4;
    uint64_t fbHeight = TargetFramebuffer->Height;
    for(int verticalScanline = 0; verticalScanline < fbHeight; verticalScanline++){
        uint64_t pixPtrBase = fbBase + (bytesPerScanline * verticalScanline);
        for(uint32_t* pixPtr = (uint32_t*)pixPtrBase; pixPtr < (uint32_t*)(pixPtrBase + bytesPerScanline); pixPtr++){
            *pixPtr = color;
        }
    }
}

void BasicRenderer::PutChar(char chr, unsigned int xOff, unsigned int yOff){
    unsigned int* pixPtr = (unsigned int*)TargetFramebuffer->BaseAddress;
    char* fontPtr = (char*)PSF1_Font->glyphBuffer + (chr * PSF1_Font->psf1_Header->charsize);
    for(unsigned long y = yOff; y < yOff + 16; y++){
        for(unsigned long x = xOff; x < xOff+8; x++){
            if((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                *(unsigned int*)(pixPtr + x + (y * TargetFramebuffer->PixelsPerScanline)) = Color;
            }
        }
        fontPtr++;
    }
}