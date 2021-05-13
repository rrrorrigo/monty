#include "monty.h"
unsigned int j[2] = {0, 0};
/**
 * main - the main function that read the monty file and calls functions
 * @argc: arguments counter
 * @argv: pointer of array of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL, *opcode[2];
	size_t len, lineno;
	ssize_t read;
	stack_t *head = NULL;

	check(argc, argv[1]);
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (lineno = 1; (read = getline(&line, &len, fd)) != -1; lineno++)
	{
		token_line(line);
		if (coment(line))
			continue;
		token_string(line, opcode);
		checkPush(opcode, lineno);
		checkJ(line, fd, head);
		callOpcode(opcode[0], &head, lineno);
		checkJ(line, fd, head);
	}
	free(line);
	fclose(fd);
	freell(head);
	return (0);
}
