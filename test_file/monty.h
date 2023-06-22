#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MONTY_DELIMS " \n\t\r"
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/* Function prototypes */
void opcode_push(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, int value);
int is_integer(char *str);
void opcode_pall(stack_t **stack, unsigned int line_number);
void print_stack(stack_t *stack);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
