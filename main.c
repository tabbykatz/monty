#include "monty.h"
#include "lists.h"
/**
 * open_up - open a monty and validate input
 * @argc: args count
 * @filename: path to monty
 */
void open_up(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_line - reads and executes each line of input from monty file
 */
void read_line(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *data;

	while ((read = getline(&monty.line, &len, monty.file) != -1))
	{
		opcode = strtok(monty.line, " ");
		if (*opcode == '#' || *opcode == '\n')
		{
			monty.line_number++;
			continue;
		}
#if 0
		else if (strcmp(opcode, "push") == 0)
		{
			data = strtok(NULL, " \n");
			if (monty.is_queue)
				/* write a func what pushes to the queue (end) */
			//	push_node_end(data);
				add_dnodeint_end(&(monty.stack), atoi(data));
			else
				/* write a func what pushes to the stack */
			//	push_node(data);
				add_dnodeint(&(monty.stack), atoi(data));
		}
#endif
		else
			op_choose(&monty.stack, opcode);
		monty.line_number++;
	}
}

/**
 * op_choose - find & call the function that corresponds with the opcode
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void op_choose(stack_t **stack, unsigned int opcode)
{
	int i;
	char *op;
	instruction_t fncs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
#if 0
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack},
		{"queue", set_queue},
#endif
		{NULL, NULL}
	};

	op = strtok(opcode, "\n");
	for (i = 0; fncs[i].opcode; i++)
	{
		if (strcmp(op, fncs[i].opcode) == 0)
		{
			fncs[i].f(stack, monty.line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%d: ", monty.line_number);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	exit(EXIT_FAILURE);
}
