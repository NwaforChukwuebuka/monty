#include "monty.h"

/**
 * main - Entry point
 * @argc: command line args entered
 * @argv: monty bytecode file supplied
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stk;

	stk = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(argv[1], &stk);
	free_linkedlist(stk);
	return (0);
}
