/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:50:37 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/26 15:30:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	initialize_stack(t_stack *stack, size_t capacity, t_stack *other_stack)
{
	stack->capacity = capacity;
	stack->size = 0; 
	stack->top = 0;
	stack->buffer = (int *)ft_calloc(stack->capacity, sizeof(int));
	if (stack->buffer == NULL)
	{
		free_stacks(stack, other_stack);
		print_error_and_exit();
	}
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
	if (a)
	{
		free(a->buffer);
		a->buffer = NULL;
	}
	if (b)
	{
		free(b->buffer);
		b->buffer = NULL;
	}
}
