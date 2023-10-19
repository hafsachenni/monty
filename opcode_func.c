#include "monty.h"

/**
 * getopcode_func - gets its function its opcode
 * @line_number: line num in monty
 * @opcode: opcode in file
 */

void getopcode_func(stack_t **stack, unsigned int line_number, char *opcode)
{
	instruction_t operations[] = {
		{"push", 
