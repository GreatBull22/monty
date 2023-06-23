#include "monty.h"

vars_t *element;

/**
  * main - Entry Point
  * @argc: Number of arguments
  * @argv: Arguments names
  * Return: 0 on success, exit on failures
  */
int main(int argc, char **argv)
{
	size_t n = 0;
	vars_t temp = {0, NULL, NULL, NULL, NULL, NULL, 1};

	element = &temp;
	if (argc != 2)
		exit_function(16);

	element->fname = argv[1];
	element->fp = fopen(element->fname, "r");
	if (element->fp == NULL)
		exit_function(1);

	while (getline(&(element->buf), &n, element->fp) != -1)
	{
		element->tokened = malloc(sizeof(char *) * 2);
		if (element->tokened == NULL)
			exit_function(3);
		get_tokens(element->buf);
		opcode_search();
		free_buffer();
		free_token();
		element->line_number++;
	}

	free_buffer();
	free_list(element->head);
	free_token();
	fclose(element->fp);
	return (0);
}
