#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t line_size = 0;
	ssize_t chars_read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
        while ((chars_read = getline(&line, &line_size, file)) != -1)
        {
                line_number++;
                char *opcode = strtok(line, MONTY_DELIMS);
                if (opcode != NULL && strcmp(opcode, "push") == 0)
                {
                        char *arg = strtok(NULL, MONTY_DELIMS);
                        if (arg == NULL || !is_integer(arg))
                        {
                                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                                free(line);
                                fclose(file);
                                free_stack(stack);
                                return (EXIT_FAILURE);
                        }
                        int value = atoi(arg);
                        push_stack(&stack, value);
                }
                else if (opcode != NULL && strcmp(opcode, "pall") == 0)
                {
                        opcode_pall(&stack, line_number);
                }
                /* Reset memory for the next line */
                free(line);
                line = NULL;
                line_size = 0;
        }

	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
