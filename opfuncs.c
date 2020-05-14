#include "monty.h"
#include "lists.h"
/**
 * push - add node to list
 * @stack: double list
 * @linenumber: line
 */
void push(char *argument)
{
	int data;
	stack_t *new;

	if (!check_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", monty.line_number);
		//free it all
		exit(EXIT_FAILURE);
	}

	data = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		// free_it_all
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}
/**
 * pop - delete node from top of list
 * @stack: double list
 * @linenumber: line
 */
/* void pop(stack_t **stack, unsigned int linenumber)
{
	if (stack)
		delete_dnodeint_at_index(stack, 0);
	else
		fprintf(sdterr, "Cant pop from empty stack");
		//free all
		exit(EXIT_FAILURE);
}*/
/**
 * swap - swap place of top two members in stack
 * @stack: double list
 * @linenumber: line
 */
/* void swap(stack_t **stack, unsigned int linenumber)
{
	int tmp;
	//swap first two stack members data element
	if (stack)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "Stack does not have enough members to swap");
		//free all
		exit(EXIT_STATUS);
	}
}
*/
/**
 * nop - does nothng
 * @stack: double list
 * @linenumber: line
 */
/* void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}
*/
