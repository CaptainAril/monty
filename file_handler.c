#include "monty.h"

int read_file(char *file)
{
    int fd;

    if((fd = open(file, O_RDONLY)) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	};

    printf("file descriptor %d\n", fd);

    close (fd);

    return 0;
}