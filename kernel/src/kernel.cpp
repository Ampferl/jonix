#include <stdint.h>
#include "BasicRenderer.h"


extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    BasicRenderer newRenderer;
    newRenderer.TargetFramebuffer = framebuffer;
    newRenderer.PSF1_Font = psf1Font;
    newRenderer.Color  =0xFFFFFFFF;
    newRenderer.CursorPosition = {15,50};
    newRenderer.Print("Test C++ with BasicRenderer");
    return ;
}
