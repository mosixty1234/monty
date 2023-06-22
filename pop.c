#include "monty.h"

/**
 * pop - deletes the top of the syack
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;
	free(temp);
}
