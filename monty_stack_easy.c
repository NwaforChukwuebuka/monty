#include "monty.h"
/**
 * monty_push - Pushes an integer to stack
 * @stack: Ptr to the top of the stack
 * @line_number: current bytecode line
 */
void monty_push(stack_t **stack, __attribute__ ((unused))unsigned int
line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (!top)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = op_global.push_opcode;
	top->next = *stack;
	top->prev = NULL;
	if (*stack)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * monty_pall - Prints all values from the stack
 * @stack: Ptr to the top of the stack
 * @line_number: current bytecode line number
 */
void monty_pall(stack_t **stack, __attribute__ ((unused))unsigned int
line_number)
{
	stack_t *ptr;

	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * monty_pint -  Output top of the stack
 * @stack: Ptr to the top of the stack
 * @line_number: current bytecode line num
 *
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = *stack;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}

/**
 * monty_pop - Removes a node
 *@stack: Ptr to the head node
 *@line_number: current line number
 *Return: void
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_pop = *stack;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = node_pop->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(node_pop);
}

/**
 * free_linkedlist - Frees the stacked linked list
 * @head: Ptr to the head node
 *
 */
void free_linkedlist(stack_t *head)
{
	stack_t *temp;

	while (!head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
