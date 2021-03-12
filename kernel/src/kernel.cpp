
typedef unsigned long long size_t;

typedef struct {
    void* BaseAddress;
    size_t BufferSize;
    unsigned int Width;
    unsigned int Height;
    unsigned int PixelsPerScanline;
} Framebuffer;

typedef struct {
    unsigned char magic[2];
    unsigned char mode;
    unsigned char charsize;
} PSF1_HEADER;

typedef struct {
    PSF1_HEADER *psf1_Header;
    void* glyphBuffer;
} PSF1_FONT;

void putChar(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, char chr, unsigned int xOff, unsigned int yOff){
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

extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1_font){

    putChar(framebuffer, psf1_font, 0xFF0000FF, 'J', 10, 10);
    putChar(framebuffer, psf1_font, 0x00FF00FF, 'o', 26, 10);
    putChar(framebuffer, psf1_font, 0x0000FFFF, 'n', 42, 10);
    putChar(framebuffer, psf1_font, 0xFF00FFFF, 'a', 58, 10);
    putChar(framebuffer, psf1_font, 0xFFFFFFFF, 's', 74, 10);
    return ;
}
