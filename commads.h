#ifndef COMMADS_H
#define COMMADS_H

#include <stdio.h>

/**
 * struct command_s - buffer storage
 * @number: push argument
 * @store_check: stores file check
 * @line: getline buffer
 * @instructions: tokenized opcodes
 *
 * Description: storage for buffers
 */


struct command_s
{
	char *number;
	FILE *store_check;
	char *line;
	char **instructions;
}command_t;

#endif
