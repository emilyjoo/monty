#include "monty.h"

/**
 * main - Run a bytecodes
 *
 * @arc: (int) argument count
 * @arv: (char **) argument vector
 * Return: 0 on success
 */
int main(int arc, char **arv)
{
	FILE *fp;
	char *lineptr = NULL, *opcode;
	const char DELIM[3] = " \t\n";
	size_t n = 0;
	ssize_t flag;
	void (*func)(stack_t **, unsigned int);

	fp = check_args(arc, arv);

	while ((flag = getline(&lineptr, &n, fp) != -1))
	{
		monty.line++;
		opcode = strtok(lineptr, DELIM);
		if (opcode)
		{
			func = _getops(opcode);
			if (!func)
			{
				dprintf(2, "L%d: unknown instruction %s\n", monty.line, opcode);
				exit(EXIT_FAILURE);
			}
			monty.arg = strtok(NULL, DELIM);
			func(&monty.stack, monty.line);
		}
	}
	free(lineptr);
	fclose(fp);
	return (0);
}
