#include "monty.h"
/**
 * checkJ - function that check the pointer J, if it's 1 the program
 * have an error and need frees the memory
 * @line: is the string of line of the file
 * @fp: is the file to close
 * @head: pointer to free
 */
void checkJ(char *line, FILE *fp, stack_t *head)
{
	if (j[1] == 1)
	{
		free(line);
		fclose(fp);
		freell(head);
		exit(EXIT_FAILURE);
	}
}
/**
 * freell - function that frees the struct stack_t
 * @head: pointer to the struct
 */
void freell(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
