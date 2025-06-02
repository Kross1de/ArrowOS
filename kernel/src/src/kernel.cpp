#include "kernel.h"
#include "BasicRenderer.hpp"
#include "gdt.h"

static BasicRenderer r = BasicRenderer(nullptr, nullptr);

void kernel(struct Framebuffer framebuffer, struct PSF1_FONT* psf1_font)
{
    r = BasicRenderer(&framebuffer, psf1_font);
    GlobalRenderer = &r;

    GlobalRenderer->Clear(Colors.dgray, true);
    GlobalRenderer->Print("Hello User!\n");
    initialize_gdt();
    GlobalRenderer->Log("GDT initialized");
    GlobalRenderer->Info("ALKSDJASKDHASKJDHASDJIK");

    return;
}
