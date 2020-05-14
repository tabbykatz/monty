#include <stdio.h>
#include <lists.h>
#include <monty.h>

/**
 * add - adds top two stack mems
 * @stack: double list
 * @linenumber: line
 */
void add(stack_t **stack, int linenumber)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_dnodeint_at_index(stack, 0);
	}
	else
	{
		fprintf(stderr, "L%d: empty stack", linenumber);
		//free_it_all();
		exit(EXIT_FAILURE);
	}
}
