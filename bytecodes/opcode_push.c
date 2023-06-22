#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = info_f.arg;
	int value;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	push_stack(stack, value);

}

/**
 * push_stack - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @value: Value to push to the stack.
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * is_integer - Checks if a string represents an integer.
 * @str: String to check.
 *
 * Return: 1 if str is an integer, 0 otherwise.
 */
int is_integer(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
