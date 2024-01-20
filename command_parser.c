#include "monty.h"

global_t op_global;

/**
 * read_file - Reads the monty bytecode and execute the cmds
 * @opcode_file: Given monty file
 * @stack: Ptr to the top of the stack of the stack_t linked list
 */
void read_file(char *opcode_file, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_cnt = 1;
	instruct_func op_fxn;
	int flag;
	int input;


	op_global.monty_file = fopen(opcode_file, "r");

	if (op_global.monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", opcode_file);
		exit(EXIT_FAILURE);
	}

	while ((input = getline(&op_global.buff, &i, op_global.monty_file)) != -1)
	{
		line = parse_line(op_global.buff, stack, line_cnt);
		if (line == NULL || line[0] == '#')
		{
			line_cnt++;
			continue;
		}
		op_fxn = get_op_func(line);
		if (op_fxn == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, line);
			exit(EXIT_FAILURE);
		}
		op_fxn(stack, line_cnt);
		line_cnt++;
	}
	free(op_global.buff);
	flag = fclose(op_global.monty_file);
	if (flag == -1)
		exit(-1);
}

/**
 * get_op_func -  Get the opcode function
 * @str: tokenized string
 * Return: returns a corresponding func,
 *                or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

/**
 * isnumber - checks if a string is an integer
 * @str: Given string
 * Return: returns 1 if true or
 *                 0 if false
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			op_global.push_opcode = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
