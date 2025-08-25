/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_push_swap.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 16:06:36 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0 || b->size + 1 > b->capacity)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	push_to_stack(pop_from_stack(a), b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0 || a->size + 1 > a->capacity)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	push_to_stack(pop_from_stack(b), a);
	ft_putstr_fd("pa\n", 1);
}

void	sa(t_stack *a, t_stack *b)
{
	if (a->size < 2)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	swap_in_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *a, t_stack *b)
{
	if (b->size < 2)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	swap_in_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	a->buffer[(a->top + a->size) % a->capacity] = a->buffer[a->top];
	a->top = (a->top + 1) % a->capacity;
	ft_putstr_fd("ra\n", 1);
}
