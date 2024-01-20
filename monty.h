#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int push_opcode;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_opcode - opcoode and its function
 * @monty_file: the opcode file
 * @push_opcode: function to handle the opcode
 * @buff: pointer to allocated space
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_opcode
{
	FILE *monty_file;
	int push_opcode;
	char *buff;
} global_t;

extern global_t op_global;

char *parse_line(char *line, stack_t **stack, unsigned int line_number);
void read_file(char *opcode_file, stack_t **stack);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/*Helper functions*/
void free_linkedlist(stack_t *head);
void free1(stack_t **stack);
void free2(stack_t **stack);

/*Fuxntions Monty*/
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/*Functions string ascci */
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/*Functions math*/
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

int _isalpha(int c);
#endif
