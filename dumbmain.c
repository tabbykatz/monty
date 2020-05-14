#include "lists.h"
#include "monty.h"

monty_t monty;


int main(int argc, char **argv)
{
	monty.argv = argv;
	monty.line = NULL;
	monty.stack = NULL;
//	monty.is_queue = 0;
	open_up();
	read_line();
}
