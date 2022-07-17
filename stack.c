#include "monty.h"

/**
 * add_node - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the begining if in
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.len_queue == STACK || var.len_stack == 0)
		*stack = new;
	return (new);
}


/**
 * free_stack - frees malloced in stack nodes memory
 * @arg: double pointer to the stack
 * @status: exit status
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *tmp;
	(void) status;
	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	var.len_stack = 0;
}

/**
 * set_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line: script line number
 */
void set_queue(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
	var.len_queue = QUEUE;
}

/**
 * set_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the top of the stack
 * @line: script line number
 */
void set_stack(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
	var.len_queue = STACK;
}
