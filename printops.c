#include "monty.h"
/**
 * pall - print all members
 * @stack: double list
 * @linenumber: line
 */
void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *a = *stack;

	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
/**
 * pint - print int in stack
 * @stack: double list
 * @linenumber: line
 */
void pint(stack_t **stack, unsigned int linenumber)
{
	if (stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%ul: Stack empty, cant print ints", linenumber);
	}
}
