#include <stdint.h>
#include "BasicRenderer.h"
#include "cstr.h"


extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    BasicRenderer newRenderer(framebuffer, psf1Font);
    newRenderer.Print("Test C++ with BasicRenderer");
    newRenderer.CursorPosition = {0, 16};
    newRenderer.Print(to_string(123456789));
    return ;
}
