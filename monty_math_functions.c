#include "monty.h"

/**
 * monty_sub - sub top of stack from second top stack
 * @stack: Ptr to top stack
 * @line_number: bytecode line num
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub_result = 0, i = 0;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i <= 1 || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub_result = (*stack)->next->n - (*stack)->n;
	monty_pop(stack, line_number);

	(*stack)->n = sub_result;
}

/**
 * monty_mul - mul top of stack with second top stack
 * @stack: ptr to top stack
 * @line_number: bytecode line number
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int mult_result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mult_result = (*stack)->n;
		monty_pop(stack, line_number);
		(*stack)->n *= mult_result;
	}
}

/**
 * monty_div - top stack divided by second top stack
 * @stack: ptr to top stack
 * @line_number: bytecode line num
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int div_result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div_result = (*stack)->n;
		monty_pop(stack, line_number);
		(*stack)->n /= div_result;
	}
}

/**
 * monty_mod - top stack mod second top stack
 * @stack: Ptr to the top stack
 * @line_number: bytecode line num
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(op_global.buff);
		fclose(op_global.monty_file);
		free_linkedlist(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		monty_pop(stack, line_number);
		(*stack)->n %= mod;
	}
}
