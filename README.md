![on second thought, let's not go to camelot](https://github.com/tabbykatz/monty/blob/master/monty.jpg) <br>
# **Monty**


## Description
This is a program built to interpret Monty-like scripted files according to operation codes provided to us in the project.

## Formatting and Examples

Format for user to write in "testfile.m":
`opcode argument`

NOTE: No more than one instruction per line is allowed, there can however be as many spaces, new lines or tabs before or after the instruction.

Examples:
`$ cat opcodetestfile.m`

`push 1`

`push 2`

`push 3`

`pall`

`$ ./montyfile opcodetestfile.m`

`3`

`2`

`1`

`$`

---

`$ cat opcodetestfile.m`

`push 1`

`push 2`

`push 3`

`pall`

`rotl`

`pall`

`$ ./montyfile opcodetestfile.m`

`3`

`2`

`1`

`2`

`1`

`3`

---

`$ cat opcodetestfile.m`

`push 4`

`push 5`

`push 18`

`push 3`

`pall`

`sub`

`pall`

`$ ./montyfile opcodetestfile.m`

`3`

`18`

`5`

`4`

`15`

`5`

`4`

---
## File List

| File Name | Description |
| --- | --- |
| README.md | Provides details regarding functionality and creation of our version of a monty program (present file) |
| main.c | The entry point of our interpreter, recieves data and initializes data struct |
| init.c | This is where data gets read and processed, data is read from file and added to our data structure accordingly |
| mathops.c | All the functions to perform math operations on the data structure members |
| string\_ops.c | Contains operations for string manipulation |
| opfuncs.c, opfuncs2.c | these files contain functionality for basic bytecode operations (pop, push, etc..) |
| printops.c | operatons to print members from data structure |
| check\_input.c| checks the type of input given to resolve errors |

## Exit Status
Exits with status `EXIT_FAILURE`

## Compilation
All files were compiled on Ubuntu 14.04 LTS.

All programs and functions were compiled with `gcc 4.8.4` using flags `-Wall -Werror -Wextra and -pedantic`.

## Styling
All files have been written in the Betty Style.

## Authors
* **Derric Donehoo** - [derric-d](https://github.com/derric-d)
* **Tabitha O'Melay** - [tabbykatz](https://github.com/tabbykatz)
