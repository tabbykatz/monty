#include "monty.h"
/**
 * rotr- rotate bottom to top
 * @stack: head of stack
 * @linenumber: current ln
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *first, *second;

	if (!(*stack) || !(*stack)->next)
	{
		return;
	}

	first = *stack;

	while (first->next->next)
	{
		first = first->next;
	}
	second = first->next;
	first->next = NULL;
	(*stack)->prev = second;
	second->next = *stack;
	second->prev = NULL;
	*stack = second;
}
/**
 * stack_op - makes it stack format (default)
 * @stack: head of stack
 * @linenumber: current ln
 *
 */
void stack_op(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
	monty.is_queue = false;
}
/**
 * queue_op - makes it queue format
 * @stack: head of stack
 * @linenumber: current ln
 */
void queue_op(stack_t **stack, unsigned int linenumber)

	(void)stack;
	(void)linenumber;
	monty.is_queue = true;
}
