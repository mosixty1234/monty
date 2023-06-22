#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: pointer to the top of the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
