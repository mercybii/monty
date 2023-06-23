#ifndef MONTY_H
#define MONTY_H



/* header files */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define buffstd 64

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * select_command - selects the opcode and function
 * @line_number: number line of opcode
 * Return: function for opcode
 */

void (*select_command(char **token))(stack_t **stack,
        unsigned int line_number);

void file_open(int argc, char **argv);
void parse_line(void);
void validate_push_opcode(int i, int line_counter, char **commands,
        char *buffer2, stack_t *head);
void call_opcode(int line_counter, stack_t **head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *create_node_with_data(stack_t **head, int number);



#endif
