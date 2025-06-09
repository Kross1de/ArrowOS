#include "gdt.h"
#include "tss.h"

struct GDT {
    struct GDTentry null;
    struct GDTentry kernel_code;
    struct GDTentry kernel_data;
    struct GDTentry user_code;
    struct GDTentry user_data;
    struct TSSdesc tss;
} __attribute__((packed)) gdt;

struct GDTdesc gdt_descriptor;

void set_gdt_entry(struct GDTentry* entry, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    entry->base_low = base & 0xFFFF;
    entry->base_mid = (base >> 16) & 0xFF;
    entry->base_high = (base >> 24) & 0xFF;
    entry->limit_low = limit & 0xFFFF;
    entry->gran = (limit >> 16) & 0x0F;
    entry->gran |= gran & 0xF0;
    entry->access = access;
}

void set_tss_descriptor(struct TSSdesc* tss_desc, uint64_t base, uint16_t limit) {
    tss_desc->base_low = base & 0xFFFF;
    tss_desc->base_mid_low = (base >> 16) & 0xFF;
    tss_desc->base_mid_high = (base >> 24) & 0xFF;
    tss_desc->base_high = (base >> 32) & 0xFFFFFFFF;
    tss_desc->limit_low = limit & 0xFFFF;
    tss_desc->gran = ((limit >> 16) & 0xF) | 0x40;
    tss_desc->access = 0x89;
    tss_desc->reserved = 0;
}

void initialize_gdt() {    
    set_gdt_entry(&gdt.null, 0, 0, 0, 0);    
    set_gdt_entry(&gdt.kernel_code, 0, 0xFFFFFFFF, 0x9A, 0xAF);      
    set_gdt_entry(&gdt.kernel_data, 0, 0xFFFFFFFF, 0x92, 0xCF);  
    set_gdt_entry(&gdt.user_code, 0, 0xFFFFFFFF, 0xFA, 0xAF);
    set_gdt_entry(&gdt.user_data, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    set_tss_descriptor(&gdt.tss, (uint64_t)&tss, sizeof(tss) - 1);

    gdt_descriptor.size = sizeof(gdt) - 1;
    gdt_descriptor.offset = (uint64_t)&gdt;

    asm volatile("lgdt %0" : : "m" (gdt_descriptor));

    uint16_t tss_selector = 5 * 8;
    asm volatile("ltr %0" : : "r" (tss_selector));
}
