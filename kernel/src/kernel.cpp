#include <stdint.h>
#include "BasicRenderer.h"
#include "efiMemory.h"
#include "cstr.h"

struct BootInfo{
    Framebuffer *framebuffer;
    PSF1_FONT *psf1_Font;
    void *mMap;
    uint64_t mMapSize;
    uint64_t mMapDescSize;
};

extern "C" void _start(BootInfo *bootInfo){
    BasicRenderer newRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);


    uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;

    for(int i = 0; i < mMapEntries; i++){
        EFI_MEMORY_DESCRIPTOR* desc = (EFI_MEMORY_DESCRIPTOR*)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
        newRenderer.CursorPosition = {0, newRenderer.CursorPosition.Y+16};
        newRenderer.Print(EFI_MEMORY_TYPE_STRINGS[desc->type]);
        newRenderer.Color = 0xFFFF00FF;
        newRenderer.Print(" ");
        newRenderer.Print(to_string(desc->numPages * 4096 / 1024));
        newRenderer.Print(" KB");
        newRenderer.Color = 0xFFFFFFF;
    }

    return ;
}
