#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_num: line index
 *
 * Initech
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !(*stack) || (!(*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n += (*stack)->n;
	free(*stack);
	*stack = temp;
}
