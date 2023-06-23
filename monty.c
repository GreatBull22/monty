#include "monty.h"
global_var var_global;
/**
 * main - funnction driver for monty program
 * @ac: number of int arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, chr **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprint(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
	/* recordar liberar memorias */
	free_distint(stack);
	return (0);

}

