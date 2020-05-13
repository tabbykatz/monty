#ifndef __MONTY__H
#define __MONTY__H

/* include these */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdbool.h>

/*structs they gave us */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* end structs they gave us */

/* this could be our global struct */
typedef struct monty_s
{
	FILE *file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	bool is_queue;
} monty_t;

extern monty_t monty;

/* prototypes - monty specific*/
void open_up(int argc, char *filename);
void read_line(void);
void op_choose(stack_t **stack, char *opcode);
void init_montyStruct(void);
void free_it_all(void);
void free_build(stack_t *h);
bool check_input(char *str);


/* prototypes - opcode functions */
void push(char *data);
void pop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void nop(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void pall(stack_t **stack, unsigned int linenumber);
void pint(stack_t **stack, unsigned int linenumber);

#endif
