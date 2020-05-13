#include "monty.h"
#include "lists.h"
/**
 * push - add node to list
 * @stack: double list
 * @linenumber: line
 */
void push(stack_t **stack, unsigned int linenumber)
{
	char *argument = strtok(NULL, " \n");
	int data;

	//make func to check input is alpha a/o numeric
	//if (isAlpha)
	data = atoi(argument);
	if (args.order == 1)
		add_nodeint(stack, data);
	else
		add_dnodeint_end(stack, data);
	//else error routine
}
/**
 * pop - delete node from top of list
 * @stack: double list
 * @linenumber: line
 */
void pop(stack_t **stack, unsigned int linenumber)
{
	if (stack)
		delete_dnodeint_at_index(stack, 0);
	else
		fprintf(sdterr, "Cant pop from empty stack");
		//free all
		exit(EXIT_FAILURE);
}
/**
 * swap - swap place of top two members in stack
 * @stack: double list
 * @linenumber: line
 */
void swap(stack_t **stack, unsigned int linenumber)
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
/**
 * nop - does nothng
 * @stack: double list
 * @linenumber: line
 */
void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}
