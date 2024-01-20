#include "monty.h"
/**
 * monty_swap - Swaps the top of the stack with the second top
 * @stack: Ptr to the top of the stack
 * @line_number: Current bytecode line num
 */

void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int temp;

	ptr = *stack;
	if (!ptr || !ptr->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}

/**
 * monty_add - top stack + second top stack
* @stack: Ptr to the top of the stack
 * @line_number: Current bytecode line num
  */

void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0, i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (i <= 1 || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	monty_pop(stack, line_number);

	(*stack)->n = sum;
}

/**
 * monty_nop - Does nothing
* @stack: Ptr to the top of the stack
 * @line_number: Current bytecode line num
 */

void monty_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_number)
{
	;
}

/**
 * monty_pchar - Gives ASCII value of a an integer
* @stack: Ptr to the top of the stack
 * @line_number: Current bytecode line num
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * monty_isalpha - Checks if number is a letter
 * @c: Given number
 * Return: 1 if true, 0 if false
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
