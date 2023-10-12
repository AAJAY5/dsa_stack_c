# DSA Stack Implementation In C

---

This project implements a stack data structure in C. The stack is a Last-In-First-Out (LIFO) data structure that allows for efficient insertion and deletion of elements from one end only, called the top. The stack is implemented using a dynamic memory allocation and provides functions for creating, pushing, popping, peeking, checking if it is full or empty, and deleting the stack.

The stack uses a structure called `stack_t` to hold the necessary information, including the element size, element count, memory block pointer, and the index of the top element.

## Example/Testing

Here's an example/test code to demonstrate the usage of the stack:

```c
#include <stdio.h>
#include "stack.h"

int main() {
    stack_t *stack = stack_create(sizeof(int), 5);  // Create a new stack with element size 4 bytes and capacity for 5 elements
    if (stack == NULL) {
        printf("Failed to create stack. Exiting.\n");
        return 1;
    }

    int elements[] = {10, 20, 30, 40, 50};

    // Push elements onto the stack
    for (size_t i = 0; i < 5; i++) {
        if (!stack_push(stack, &(elements[i]))) {
            printf("Failed to push element %d onto the stack. Exiting.\n", elements[i]);
            stack_delete(&stack);
            return 1;
        }
    }

    // Pop and print elements from the stack
    int popped_element;
    while (!stack_is_empty(stack)) {
        if (!stack_pop(stack, &popped_element)) {
            printf("Failed to pop element from the stack. Exiting.\n");
            stack_delete(&stack);
            return 1;
        }
        printf("Popped element: %d\n", popped_element);
    }

    stack_delete(&stack);  // Delete the stack and free its resources

    return 0;
}
```

In this example, we create a stack to hold integers. We push five elements onto the stack and then pop and print each element until the stack becomes empty. Finally, we delete the stack to free its resources.

## Compiling the Code

To compile the code, you need a C compiler such as GCC. Assuming you have GCC installed, you can use the following command to compile the code and generate an executable:

```bash
    gcc .\examples\main.c .\src\stack.c -I .\obj\ -DDEBUG_STACK
    a.exe
```
