#include "monty.h"

file_info info_f = {0, 0, NULL, NULL, NULL, NULL, NULL, NULL};

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success  and 1 on failure
 */

int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	readline(stack, file);

	return (0);
}

/**
 * readline - reads the file line by line
 * @stack: pointer to the top of the stack
 * @file: file containing opcodes
 */

void readline(stack_t *stack, FILE *file)
{
	static int counter = 1;
	char content[MAX_LENGHT];

	while (fgets(content, MAX_LENGHT, file) != NULL)
	{
		info_f.line_num = counter;
		perser(content);
		execute(&stack, counter);
		info_f.content = content;
		counter++;

	}
}

/**
 * perser - perse the line for opcode and arg
 * @content: line content
 *
 * Inialph
 */

void perser(char *content)
{
	char *arg;
	char *opcode;
	char *content_copy;

	content_copy = my_strdup(content);

	opcode = strtok(content_copy, " \n\t");
	arg = strtok(NULL, " \n\t");
	info_f.arg = arg;
	info_f.opcode = opcode;

}
