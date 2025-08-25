/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_of_four_and_five.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:02:36 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 23:37:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_smallest_and_pb(t_stack *a, t_stack *b);
static void	smallest_to_top(t_stack *a, int smallest_nbr, size_t index);

void	sort_four_to_five_numbers(t_stack *a, t_stack *b)
{
	if (!a || !b || (a->size < 4 || a->size > 5))
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	if (is_sorted(a))
		free_stacks_and_exit(a, b);
	if (a->size == 5)
		find_smallest_and_pb(a, b);
	find_smallest_and_pb(a, b);
	sort_three_numbers(a, b);
	if (b->size == 2 && (get_from_stack(0, b) < get_from_stack(1, b)))
		sb(a, b);
	while (b->size > 0)
    	pa(a, b);
}

static void	find_smallest_and_pb(t_stack *a, t_stack *b)
{
	int		smallest_nbr;
	int		current_nbr;
	size_t	smallest_nbr_index;
	size_t	i;

	smallest_nbr = get_from_stack(0, a);
	smallest_nbr_index = 0;
	i = 1;
	while (i < a->size)
	{
		current_nbr = get_from_stack(i, a);
		if (current_nbr < smallest_nbr)
		{
			smallest_nbr = current_nbr;
			smallest_nbr_index = i;
		}
		i++;
	}
	smallest_to_top(a, smallest_nbr, smallest_nbr_index);
	pb(a, b);
}

static void	smallest_to_top(t_stack *a, int smallest_nbr, size_t index)
{
	while (get_from_stack(0, a) != smallest_nbr)
	{
		if (index <= a->size / 2)
		{
			ra(a);
			index--;
		}
		else
		{
			rra(a);
			index++;
		}
	}
}
