#include "monty.h"
/**
 * push - function that push a value to the linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = j[0];
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - function that print all the linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * pint - function that print the top value of the linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!aux)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		j[1] = 1;
		return;
	}
	printf("%d\n", aux->n);
}
/**
 * pop - function that free the top of the linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!aux)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		j[1] = 1;
		return;
	}
	if (!(aux->next))
	{
		free(aux);
		*stack = NULL;
		return;
	}
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}
/**
 * swap - function that swap the two first values of the linked list
 * @stack: double pointer to the struct
 * @line_number: line number of the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = (*stack), *aux2;
	int tn;

	if (!aux || !(aux->next))
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		j[1] = 1;
		return;
	}
	aux2 = aux->next;
	tn = aux->n;
	aux->n = aux2->n;
	aux2->n = tn;
}
