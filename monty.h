#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

stack_t *head = NULL;

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

void Error(int error_code, ...);
void MoreErr(int error_code, ...);
void stringErr(int error_code, ...);

stack_t *createnode(int n);
void freestack(void);
void addtoqueue(stack_t **new_node, __attribute__((unused))unsigned int ln);




void push_element(stack_t **new_node, __attribute__((unused))unsigned int ln);
void pint_stack(stack_t **stack, unsigned int linenumber);
void pop_element(stack_t **stack, unsigned int linenumber);
void prinTop(stack_t **stack, unsigned int linenumber);


#endif
