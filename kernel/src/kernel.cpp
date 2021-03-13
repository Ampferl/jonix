
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

typedef struct {
    unsigned int X;
    unsigned int Y;
} Point;

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

Point CursorPosition;
void Print(Framebuffer *framebuffer, PSF1_FONT *psf1Font, unsigned int color, const char* str){
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

extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    CursorPosition.X = 50;
    CursorPosition.Y = 120;
    for(int t=0;t<50;t++)
        Print(framebuffer, psf1Font, 0xFF0000FF, "Hello World. My name is Jonas!");
    return ;
}
