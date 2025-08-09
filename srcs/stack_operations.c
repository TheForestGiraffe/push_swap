/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/08 16:08:07 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void    push_nbr_to_stack(int nbr, t_stack *stack) //
{
    if (stack->size + 1 > stack->capacity)
        double_stack_capacity(stack);
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->buffer[stack->top] = nbr;
    stack->size++;
}

int	get_nbr_from_stack(size_t position, t_stack *stack)
{
	size_t	i;

	i = (stack->top + position) % stack->capacity;
	return (stack->buffer[i]);
}
