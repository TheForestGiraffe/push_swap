/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_standard_continued.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 23:38:28 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

void    push_to_stack(int nbr, t_stack *stack)
{
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->buffer[stack->top] = nbr;
    stack->size++;
}

void    add_to_stack(int nbr, t_stack *stack)
{
    if (stack->size + 1 > stack->capacity)
        double_stack_capacity(stack);
    stack->buffer[(stack->top + stack->size) % stack->capacity] = nbr;
    stack->size++;
}

void	swap_in_stack(t_stack *stack)
{
	int	temp;

	temp = stack->buffer[stack->top];
	stack->buffer[stack->top] = stack->buffer[(stack->top + 1) % stack->capacity];
	stack->buffer[(stack->top + 1) % stack->capacity] = temp;
}

void	set_all_in_stack(t_stack *a, int *sorted_ranks)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		a->buffer[(a->top + i) % a->capacity] = sorted_ranks[i];
		i++;
	}
}
