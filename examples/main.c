#include <stdio.h>
#include <assert.h>
#include "../src/stack.h"

void test_stack_create() {
    stack_t *stack = stack_create(sizeof(int), 5);
    assert(stack != NULL);
    assert(stack->e_size == sizeof(int));
    assert(stack->e_count == 5);
    assert(stack->mem != NULL);
    assert(stack->top == 0);
    stack_delete(&stack);
}

void test_stack_push() {
    stack_t *stack = stack_create(sizeof(int), 5);
    int element = 10;
    bool result = false;

    result = stack_push(stack, &element);
    assert(result == true);
    assert(stack_available(stack) == 1);

    element++;
    result = stack_push(stack, &element);
    assert(result == true);
    assert(stack_available(stack) == 2);

    element++;
    result = stack_push(stack, &element);
    assert(result == true);
    assert(stack_available(stack) == 3);

    element++;
    result = stack_push(stack, &element);
    assert(result == true);
    assert(stack_available(stack) == 4);

    element++;
    result = stack_push(stack, &element);
    assert(result == true);
    assert(stack_available(stack) == 5);

    element++;
    result = stack_push(stack, &element);
    assert(result == false);
    assert(stack_available(stack) == 5);

    stack_delete(&stack);
}

void test_stack_pop() {
    stack_t *stack = stack_create(sizeof(int), 5);
    int element = 42;
    int popped_element;
    bool result;

    result = stack_push(stack, &element);
    assert(result == true);

    element = 45;
    result = stack_push(stack, &element);
    assert(result == true);

    element = 100;
    result = stack_push(stack, &element);
    assert(result == true);

    element = -10;
    result = stack_push(stack, &element);
    assert(result == true);

    assert(stack_available(stack) == 4);

    result = stack_pop(stack, &popped_element);
    assert(result == true);
    assert(popped_element == -10);

    result = stack_pop(stack, &popped_element);
    assert(result == true);
    assert(popped_element == 100);

    result = stack_pop(stack, &popped_element);
    assert(result == true);
    assert(popped_element == 45);

    result = stack_pop(stack, &popped_element);
    assert(result == true);
    assert(popped_element == 42);

    assert(stack_available(stack) == 0);

    stack_delete(&stack);
}

void test_stack_peek() {
    stack_t *stack = stack_create(sizeof(int), 5);
    int element = 42;
    int peeked_element;
    bool result;

    result = stack_push(stack, &element);
    assert(result == true);

    element = 45;
    result = stack_push(stack, &element);
    assert(result == true);

    result = stack_peek(stack, &peeked_element);
    assert(result == true);
    assert(stack_available(stack) == 2);
    assert(peeked_element == 45);

    result = stack_peek(stack, &peeked_element);
    assert(result == true);
    assert(stack_available(stack) == 2);
    assert(peeked_element == 45);

    stack_delete(&stack);
}

void test_stack_is_full() {
    stack_t *stack = stack_create(sizeof(int), 2);
    int element = 42;

    stack_push(stack, &element);
    stack_push(stack, &element);

    bool result = stack_is_full(stack);
    assert(result == true);

    stack_delete(&stack);
}

void test_stack_is_empty() {
    stack_t *stack = stack_create(sizeof(int), 5);
    bool result = stack_is_empty(stack);
    assert(result == true);

    int element = 42;
    stack_push(stack, &element);
    result = stack_is_empty(stack);
    assert(result == false);

    stack_delete(&stack);
}

int main() {
    test_stack_create();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_is_full();
    test_stack_is_empty();

    printf("All tests passed successfully.\n");

    return 0;
}
