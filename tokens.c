#include "monty.h"
/**
 * token_line - function that tokens the line recieved
 * @string: string to token
 * Return: string without newline
 */
char *token_line(char *string)
{
	char *token;

	token = strtok(string, "\n");
	return (token);
}
/**
 * token_string - function that tokens the string by spaces and tab
 * @string: string to token
 * @opcode: array to save the tokens
 * Return: opcode
 */
char **token_string(char *string, char **opcode)
{
	int i = 0;
	char *aux;

	aux = strtok(string, " \t\n");
	for (; aux && i < 2; i++)
	{
		opcode[i] = aux;
		aux = strtok(NULL, " \t\n");
	}
	return (opcode);
}
