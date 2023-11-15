#include "monty.h"

/**
 * push_element - push an element to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push_element(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pint_stack - prints the elements of the stack .
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: line number of  the opcode.
 */

void pint_stack(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	(void) linenumber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * pop_element - pops an element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void pop_element(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, linenumber);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * prinTop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void prinTop(stack_t **stack, unsigned int linenumber)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, linenumber);
	printf("%d\n", (*stack)->n);
}
