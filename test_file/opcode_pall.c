#include "monty.h"

/**
 * opcode_pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_stack(*stack);
}

/**
 * print_stack - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 */
void print_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}

void free_stack(stack_t *stack)
{
	stack_t *temp;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
