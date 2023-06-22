#include "monty.h"

/**
 * is_digit - checks if string is a number
 * @str: (char *) string
 * Return: 1 
   otherwise -1
*/
int is_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!(isdigit(str[i])))
			return (-1);
		i++;
	}
	return (1);
}

/**
 * _getops - gets the corresponding function of opcode
 * @opcodes: opcodes from bytecode file
 * Return: NULL if function is not found
*/
void (*_getops(char *opcodes))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t ops_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL},
	};

	while (ops_list[i].opcode)
	{
		if (strcmp(opcodes, ops_list[i].opcode) == 0)
			return (ops_list[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _initmonty - init global monty var
 */
void _initmonty(void)
{
	monty.arg = NULL;
	monty.line = 0;
	monty.stack = NULL;
}

/**
 * check_args - open byte code file
 * @arc: argument cound
 * @arv: argument vector
 * Return: file pointer to byte code
 */
FILE *check_args(int arc, char **arv)
{
	FILE *fp;

	if (arc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(arv[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}
