#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1]);
	
	printf("Number of arguments passed: %d\n", argc);
	printf("%s\n", argv[0]);

	return 0;
}
