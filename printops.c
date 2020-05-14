#include <lists.h>
#include <monty.h>
/**
 * pall - print all members
 * @stack: double list
 * @linenumber: line
 */
void pall(stack_t **stack, int linenumber)
{
	print_dlistint(stack);
}
/**
 * pint - print int in stack
 * @stack: double list
 * @linenumber: line
 */
void pint(stack_t **stack, int linenumber)
{
	if (stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%ul: Stack empty, cant print ints", linenumber);
	}
}
