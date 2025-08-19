/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:02:36 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 14:37:50 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_numbers(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size != 2)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	if (get_from_stack(0, a) > get_from_stack(1, a))
		sa(a, b);
}

void	sort_three_numbers(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size != 3)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	if (get_from_stack(0, a) > get_from_stack(1, a) &&
		get_from_stack(0, a) > get_from_stack(2, a))
		ra(a);
	else if (get_from_stack(1, a) > get_from_stack(0, a) &&
			 get_from_stack(1, a) > get_from_stack(2, a))
		rra(a);
	if (get_from_stack(0, a) > get_from_stack(1, a))
		sa(a, b);
}