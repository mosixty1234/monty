#include "monty.h"

/**
 * pall - prints all the stack or queue data
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void pall(stack_t **stack, unsigned int line_num)
{
	print_stack(stack, line_num);
}

/**
 * print_stack - print all the data in the stack
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	(void)line_num;
	if (!stack || !(*stack))
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
