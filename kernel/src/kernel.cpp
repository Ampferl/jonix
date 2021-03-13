#include <stdint.h>
#include "BasicRenderer.h"


extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    BasicRenderer newRenderer;
    newRenderer.CursorPosition = {15,50};
    newRenderer.Print(framebuffer, psf1Font, 0xFFFFFFFF, "Test C++ with BasicRenderer");
    return ;
}
