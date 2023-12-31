#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
}


/**
 * swap_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void swap_elements(stack_t **stack, unsigned int linenumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		MoreErr(8, linenumber, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_elements - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void add_elements(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		MoreErr(8, linenumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_elements - subtracts the top element from the second top element .
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void sub_elements(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		MoreErr(8, linenumber, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_elements - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @linenumber: Interger representing the line number of of the opcode.
 */
void div_elements(stack_t **stack, unsigned int linenumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		MoreErr(8, linenumber, "div");

	if ((*stack)->n == 0)
		MoreErr(9, linenumber);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
