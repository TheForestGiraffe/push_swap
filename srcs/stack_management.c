/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:50:37 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/15 21:17:52 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO: remove
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void initialize_stack(t_stack *stack, size_t capacity)
{
    stack->capacity = capacity;
    stack->size = 0;  
    stack->top = 0;
    stack->buffer = (int *)ft_calloc(stack->capacity, sizeof(int));
    if (stack->buffer == NULL)
        print_error_and_exit(); // TODO: What if a was already initialized? How to free all?
}

void	double_stack_capacity(t_stack *stack)
{
    int		*new_buffer;
	int		*temp;
	size_t	i;

    new_buffer = (int *)ft_calloc(stack->capacity * 2, sizeof(int));
    if (!new_buffer)
	{
		free(stack->buffer);
		stack->buffer = NULL;
		print_error_and_exit();
	}
	i = 0;
	while (i < stack->size)
	{
		new_buffer[i] = stack->buffer[(stack->top + i) % stack->capacity];
		i++;
	}
	stack->top = 0;
	stack->capacity *= 2;
	temp = stack->buffer;
	stack->buffer = new_buffer;
	free (temp);
	temp = NULL;
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->buffer);
	free(b->buffer);
	a->buffer = NULL;
	b->buffer = NULL;
}

