#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGHT 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: data part of the node
 * @prev: a pointer to the previous node
 * @next: a pointer to the next node
 *
 * Description: doubly linked list node stucture
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and it function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and corresponding function for LIFO, FIFO, stack, queue
 */


typedef struct intstuction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct file_information - the file details
 * @line_num: the line number
 * @content: the content of the line
 * @opcode: the opcode command
 * @stack_size: size of the stack
 * @head: pointer to the first node in the stack
 * @tail: pointer to the last node in the stack
 *
 * Description: the current file informations
 */

typedef struct file_information
{
	int line_num;
	int stack_size;
	char *content;
	char *opcode;
	char *arg;
	FILE *file;
	stack_t *head;
	stack_t *tail;
} file_info;

extern file_info info_f;

void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


void readline(stack_t *stack, FILE *file);
void perser(char *content);
void execute(stack_t **stack, unsigned int line_num);
void print_stack(stack_t **stack, unsigned int line_num);

void push_stack(stack_t **stack, int value);
char *my_strdup(const char *str);
int is_integer(char *str);

void free_stack(stack_t **stack);
#endif
