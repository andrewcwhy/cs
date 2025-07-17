#ifndef INTER_H
#define INTER_H

#include <stdbool.h>

typedef struct stack
{
    int *
} stack_t;

bool is_empty(const stack_t *stack);
bool is_full(const stack_t *stack);
int peek();
int pop();
void push(stack_t stack, int value);
void print_stack();

#endif