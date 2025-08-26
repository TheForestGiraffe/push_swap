/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_standard.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/26 15:29:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

int	is_in_stack(t_stack *stack, int nbr)
{
	size_t	position;

	position = 0;
	while (position < stack->size)
	{
		if (nbr == get_from_stack(position++, stack))
			return (1);
	}
	return (0);
}

int	get_from_stack(size_t position, t_stack *stack)
{
	size_t	i;

	i = (stack->top + position) % stack->capacity;
	return (stack->buffer[i]);
}

int	pop_from_stack(t_stack *stack)
{
	int	nbr;

	nbr = stack->buffer[stack->top];
	stack->top = (stack->top + 1) % stack->capacity;
	stack->size--;
	return (nbr);
}
