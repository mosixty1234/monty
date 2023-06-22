#include "monty.h"

/**
 * op_div - divides the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void op_div(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!stack || !(*stack) || (!(*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n /= (*stack)->n;
	free(*stack);
	*stack = temp;

}

