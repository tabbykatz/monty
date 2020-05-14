#include <stdio.h>
#include "lists.h"
#include "monty.h"

monty_t monty;
/**
 * open_up - opens file passed
 *
 */
void open_up(void)
{
	char argsbuf[50];
	args.file = fopen(monty.argv[1], "r");//open file and saf FD
	if (args.file)//as long as we have a file
	{
		while (fgets(argsbuf, sizeof(argsbuf), monty.file))//read line until argbuf is full
		{
			monty.line_number++; //we have an argument
			monty.line = argsbuf; // save line in struct
			read_line(); // parses for argument.
		}
	}
}
/**
 * read_line - read line and call function
 *
 */
void read_line(void)
{
	int opfunc = NULL;
	int i = 0;
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
	opfunc = strtok(monty.line, " \n");//get bytecode passed
	if (opfunc)
	{
		while (fncs[i].opcode && opfunc) //iterate through list of func structs and our opcode function
		{
			if (strcmp(fncs[i].opcode && opfunc) == 0)//call if we get a match
			{
				//not sure what args.stack does, was in given struct
				fncs[i].f(monty.stack, monty.line_number);
				return;
			}
		}
	}
	else if (opfunc == NULL) //error
		return;
	exit(EXIT_FAILURE);
}
