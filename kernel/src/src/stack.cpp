#include "stack.h"

uint8_t kernel_stack[KERNEL_STACK_SIZE] __attribute__((aligned(16)));
uint64_t kernel_stack_top = (uint64_t)&kernel_stack[KERNEL_STACK_SIZE];
