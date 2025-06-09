#ifndef GDT_H
#define GDT_H

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

struct __attribute__((packed)) TSSdesc
{
  uint16_t limit_low;
  uint16_t base_low;
  uint8_t base_mid_low;
  uint8_t access;
  uint8_t gran;
  uint8_t base_mid_high;
  uint32_t base_high;
  uint32_t reserved;
};

extern struct GDTdesc gdt_descriptor;

void initialize_gdt();

#endif
