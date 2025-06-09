#ifndef TSS_H
#define TSS_H

#include <stdint.h>

struct __attribute__((packed)) TaskStateSegment
{
  uint32_t reserved1;
  uint64_t rsp0;
  uint64_t rsp1;
  uint64_t rsp2;
  uint64_t reserved2;
  uint64_t ist1;
  uint64_t ist2;
  uint64_t ist3;
  uint64_t ist4;
  uint64_t ist5;
  uint64_t ist6;
  uint64_t ist7;
  uint64_t reserved3;
  uint16_t iomap_base;
};

extern TaskStateSegment tss;

void initialize_tss(uint64_t kernel_stack_top);

#endif
