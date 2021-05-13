#include "monty.h"
/**
 * check - function that check if the file exist and have the extension
 * @ac: arguments counter
 * @av: pointer to arguments
 */
void check(int ac, char *av)
{
	char *extension;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	extension = strrchr(av, '.');
	if (!extension)
		return;
	if (!(strcmp(".txt", extension) == 0 || strcmp(extension, ".m") == 0))
	{
		printf("Error: Can't open file %s\n", av);
		exit(EXIT_FAILURE);
	}
}
/**
 * coment - function that check if the file have coment and ignore it
 * @string: pointer to the line of the file to check
 * Return: 1 if it's coment or 0 if it's not
 */
int coment(char *string)
{
	if (string[0] == '#')
		return (1);
	return (0);
}
/**
 * checkPush - function that check if the push comand has an integer
 * @token: doible pointer to the command of the file
 * @lineno: line number
 */
void checkPush(char **token, int lineno)
{
	if (strcmp(token[0], "push") == 0)
	{
		if (token[1] && checkNumber(token[1]))
			j[0] = atoi(token[1]);
		else
		{
			printf("L%d: usage: push integer\n", lineno);
			j[1] = 1;
		}
	}
}
/**
 * checkNumber - function that check if the string is a number
 * @str: pointer to check
 * Return: 1 if it's number or 0 if it's not
 */
int checkNumber(char *str)
{
	int i = 0;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
/**
 * callOpcode - function that check if the file use a opcode and call the func
 * @opcode: the command to check if exist
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void callOpcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int con = 0;

	while (func[con].opcode)
	{
		if (strcmp(func[con].opcode, opcode) == 0)
			break;
		con++;
	}
	if (func[con].opcode)
		func[con].f(stack, line_number);
	else
	{
		printf("L%d: unknown instruction %s\n", line_number, opcode);
		j[1] = 1;
	}
}
