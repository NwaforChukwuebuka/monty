#include "monty.h"

/**
 * monty_pstr - print string from the stack
 * @stack: Ptr to the top of the stack
 * @line_number: current bytecode line num
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int count = 0;

	(void)line_number;


	while (temp != NULL)
	{
		count = temp->n;
		if (_isalpha(count) == 0 || count == 0)
			break;
		putchar(count);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * monty_rotl - rotates the stack from top to bottom
 * @stack: Ptr to the top of the stack
 * @line_number: current bytecode line num
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;


	int num_int = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	num_int = ptr->n;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		ptr->prev->n = ptr->n;
	}

	ptr->n = num_int;
}

/**
 * monty_rotr - Rotates the stack from bottom to the top
* @stack: Ptr to the top of the stack
 * @line_number: current bytecode line num
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	int num_int = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;

	num_int = ptr->n;

	while (ptr->prev != NULL)
	{
		ptr = ptr->prev;
		ptr->next->n = ptr->n;
	}

	ptr->n = num_int;
}
