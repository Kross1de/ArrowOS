#pragma once

#include <stdint.h>

struct __attribute__((packed)) GDTdesc
{
        uint16_t size;
        uint64_t offset;
};

struct __attribute__((packed)) GDTentry
{
        uint16_t limit_low;
        uint16_t base_low;
        uint8_t base_mid;
        uint8_t access;
        uint8_t gran;
        uint8_t base_high;
};

struct __attribute__((packed)) GDT
{
        GDTentry null;
        GDTentry kernel_code;
        GDTentry kernel_data;
        GDTentry user_code;
        GDTentry user_data;
};

extern "C" void load_gdt(GDTdesc* gdt_desc);

void initialize_gdt();