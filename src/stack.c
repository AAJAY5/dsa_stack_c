#include "stack.h"

#ifdef DEBUG_STACK
    #include <stdio.h>
    #define DEBUG(fmt, ...) printf("[%s][%s:%u]" fmt, __func__, __FILE__, __LINE__##__VA_ARGS__)
    #else
    #define DEBUG(fmt, ...) ((void)0)
#endif

stack_t *stack_create(size_t e_size, size_t e_count) {
    stack_t *stack = NULL;

    if((e_size <=0) || (e_count <= 0)){
        DEBUG("Invalid size or count\r\n");
        return NULL;
    }

    void *mem = calloc(e_count, e_size);
    if (!mem) {
        DEBUG("Unable to calloc mem\r\n");
        return NULL;
    }

    stack = calloc(1, sizeof(stack_t));
    if (!stack) {
        DEBUG("Unable to calloc stack\r\n");
        return NULL;
    }

    stack->e_size = e_size;
    stack->e_count = e_count;
    stack->mem = mem;
    stack->top = 0;

    return stack;
}

bool stack_push(stack_t *stack, void *obj) {
    if (!stack) {
        DEBUG("Invalid Stack\r\n");
        return false;
    }

    if (!obj) {
        DEBUG("Invalid obj\r\n");
        return false;
    }

    if (stack_is_full(stack)) {
        DEBUG("Stack is full\r\n");
        return false;
    }

    memcpy((stack->mem + (stack->top * stack->e_size)), obj, stack->e_size);
    stack->top++;
    return true;
}

bool stack_pop(stack_t *stack, void *obj) {
    if (!stack_peek(stack, obj))
        return false;
    stack->top--;
    return true;
}

bool stack_peek(stack_t *stack, void *obj) {
    if (!stack) {
        DEBUG("Invalid stack\r\n");
        return false;
    }

    if (!obj) {
        DEBUG("Invalid obj\r\n");
        return false;
    }

    if (stack_is_empty(stack)) {
        DEBUG("Stack empty\r\n");
        return false;
    }

    memcpy(obj, (stack->mem + ((stack->top - 1)*stack->e_size)), stack->e_size);
    return true;
}

bool stack_is_full(stack_t *stack) {
    if (!stack)
        return false;
    return (stack->top == (stack->e_count));
}

bool stack_is_empty(stack_t *stack) {
    if (!stack)
        return false;
    return (stack->top == 0);
}

size_t stack_available(stack_t *stack){
    if (!stack)
        return 0;
    return stack->top;
}

size_t stack_size(stack_t *stack){
    if (!stack)
        return 0;
    return stack->e_count;
}

void stack_delete(stack_t **stack) {
    if (!(*stack)) {
        DEBUG("Invalid stack\r\n");
        return;
    }

    if (!((*stack)->mem)) {
        DEBUG("Invalid mem\r\n");
        return;
    }

    free((*stack)->mem);
    (*stack)->mem = NULL;

    free(*stack);
    *stack = NULL;
}