#include "monty.h"
/**
 * add - function that adds the two top elements of linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *aux2;

	if (!aux || !(aux->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		j[1] = 1;
		return;
	}
	aux2 = aux->next;
	aux->n += aux->next->n;
	aux->next = aux2->next;
	if (aux2->next)
		aux2->next->prev = aux;
	else
		aux->next = NULL;
	free(aux2);
}
/**
 * nop - function that doesn't anything
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
