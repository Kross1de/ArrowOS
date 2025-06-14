#include "kernel.h"
#include "BasicRenderer.hpp"
#include "gdt.h"
#include "tss.h"
#include "stack.h"

static BasicRenderer r = BasicRenderer(nullptr, nullptr);

void kernel(struct Framebuffer framebuffer, struct PSF1_FONT* psf1_font)
{
    r = BasicRenderer(&framebuffer, psf1_font);
    GlobalRenderer = &r;

    GlobalRenderer->Clear(Colors.dgray, true);
    initialize_gdt();
    GlobalRenderer->Log("GDT initialized");
    initialize_tss(kernel_stack_top);
    GlobalRenderer->Log("TSS initialized");
    GlobalRenderer->Info("Kernel finally started!");
    GlobalRenderer->Print("Hello user!\n");

    return;
}
