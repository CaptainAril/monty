#include "monty.h"


int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line = 0;
	FILE *myfile = NULL;
	char *lineptr = NULL, *oper = NULL;
	size_t llen = 0;

	var.len_queue = 0;
	var.len_stack = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	myfile = fopen(argv[1], "r");
	if (myfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &stack);
	on_exit(myfile_close, myfile);

	while (getline(&lineptr, &llen, myfile) != -1)
	{
		line++;
		oper = strtok(lineptr, "\n\t\r ");
		if (oper != NULL && oper[0] != '#')
		{
			call_oper(&stack, oper, line);
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * free_lineptr - free line pointer returned by getline
 * @status: exit status
 * @arg: pointer to line
 */
void free_lineptr(int status, void *arg)
{
	char **lineptr = arg;
	(void) status;
	if (*lineptr != NULL)
		free(*lineptr);
}

/**
 * myfile_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 */
void myfile_close(int status, void *arg)
{
	FILE *myfile;
	(void) status;
	myfile = (FILE *) arg;
	fclose(myfile);
}

/**
 * check_isdigit - checks string is only digit
 * @str: string input argument
 * Return: 0 is only digit or 1 not digit
 */

int check_isdigit(char *str)
{
	int c;

	for (c = 0; str[c]; c++)
	{
		if (str[c] == '-' && c == 0)
			continue;
		if (isdigit(str[c]) == 0)
			return (1);
	}
	return (0);
}
