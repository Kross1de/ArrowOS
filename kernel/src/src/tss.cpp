#include "tss.h"

TaskStateSegment tss;

void initialize_tss(uint64_t kernel_stack_top)
{
  tss.reserved1=0;
  tss.rsp0=kernel_stack_top;
  tss.rsp1=0;
  tss.rsp2=0;
  tss.reserved2=0;
  tss.ist1=0;
  tss.ist2=0;
  tss.ist3=0;
  tss.ist4=0;
  tss.ist5=0;
  tss.ist6=0;
  tss.ist7=0;
  tss.reserved3=0;
  tss.iomap_base=0;
}
