#ifndef STACK_H
#define STACK_H

#include <stdint.h>

#define KERNEL_STACK_SIZE (64*1024)

extern uint8_t kernel_stack[KERNEL_STACK_SIZE];
extern uint64_t kernel_stack_top;

#endif
