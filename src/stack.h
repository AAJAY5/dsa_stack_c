#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct stack_t
 * @brief A stack data structure.
 */
typedef struct {
    size_t e_size; /**< The size of each element in the stack. */
    size_t e_count; /**< The maximum number of elements the stack can hold. */
    void *mem; /**< A pointer to the memory block for the stack. */
    size_t top; /**< The index of the top element in the stack. */
} stack_t;

/**
 * @brief Create a new stack with the specified element size and capacity.
 *
 * @param e_size The size of each element in the stack.
 * @param e_count The maximum number of elements the stack can hold.
 * @return A pointer to the newly created stack, or NULL on failure.
 */
stack_t *stack_create(size_t e_size, size_t e_count);

/**
 * @brief Push an element onto the stack.
 *
 * @param stack The stack to push the element onto.
 * @param obj A pointer to the element to be pushed onto the stack.
 * @return true if the push operation was successful, false otherwise.
 */
bool stack_push(stack_t *stack, void *obj);

/**
 * @brief Pop an element from the stack.
 *
 * @param stack The stack to pop the element from.
 * @param obj A pointer to store the popped element.
 * @return true if the pop operation was successful, false otherwise.
 */
bool stack_pop(stack_t *stack, void *obj);

/**
 * @brief Peek at the top element of the stack without removing it.
 *
 * @param stack The stack to peek into.
 * @param obj A pointer to store the top element.
 * @return true if the peek operation was successful, false otherwise.
 */
bool stack_peek(stack_t *stack, void *obj);

/**
 * @brief Check if the stack is full.
 *
 * @param stack The stack to check.
 * @return true if the stack is full, false otherwise.
 */
bool stack_is_full(stack_t *stack);

/**
 * @brief Check if the stack is empty.
 *
 * @param stack The stack to check.
 * @return true if the stack is empty, false otherwise.
 */
bool stack_is_empty(stack_t *stack);

/**
 * @brief Retrieves the current size of the stack.
 *
 *
 * @param stack A pointer to the stack object.
 * @return size of the stack.
 */
size_t stack_size(stack_t *stack);

/**
 * @brief Retrieves the pushed count or available to pop.
 *
 *
 * @param stack A pointer to the stack object.
 * @return The available space in the stack.
 */
size_t stack_available(stack_t *stack);

/**
 * @brief Delete a stack and free its resources.
 *
 * @param stack A pointer to the stack to be deleted.
 */
void stack_delete(stack_t **stack);

#endif
