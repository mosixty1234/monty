#include "monty.h"

/**
 * pint - prints the top node of the stack
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	(void)line_num;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}



/**
 * pchar - prints the top node of the stack as a char
 * @stack: pointer to the top of the stack
 * @line_num: line index
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	(void)line_num;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}


	if ((temp->n >= 65 && temp->n <= 90) || (temp->n >= 97 && temp->n <= 122))
		printf("%c\n", temp->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(info_f.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

}
