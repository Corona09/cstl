#include <cstdint>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef STACK_H_P1CSXAGL
#define STACK_H_P1CSXAGL

typedef struct Stack {
	void** data;
	int32_t capacity;
	int32_t length;
} Stack;

/**
 * Create New Stack
 */
Stack* newStack();

/**
 * Release a stack pointer and its memories.
 */
void freeStack(Stack* stack);


#endif /* end of include guard: STACK_H_P1CSXAGL */
