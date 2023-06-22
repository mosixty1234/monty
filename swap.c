#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !(*stack) || (!(*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}
