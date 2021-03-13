#include <stdint.h>
#include "BasicRenderer.h"


extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    BasicRenderer newRenderer(framebuffer, psf1Font);
    newRenderer.Print("Test C++ with BasicRenderer");
    return ;
}
