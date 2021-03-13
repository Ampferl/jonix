#include <stdint.h>
#include "BasicRenderer.h"
#include "cstr.h"


extern "C" void _start(Framebuffer *framebuffer, PSF1_FONT* psf1Font){
    BasicRenderer newRenderer(framebuffer, psf1Font);
    newRenderer.Print("Test C++ with BasicRenderer");
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y+16};
    newRenderer.Print(to_string((uint64_t) 123456789));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y+16};
    newRenderer.Print(to_string((int64_t) -987654));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y+16};
    newRenderer.Print(to_string((double) -13.8765451));
    newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y+16};
    newRenderer.Print(to_string((double) -13.8765451, 5));
    return ;
}
