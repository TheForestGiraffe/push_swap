/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:41:00 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/22 16:47:53 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nbr_of_bits(t_stack *a);

void	radix_sort(t_stack *a, t_stack *b)
{
	int		i;
	size_t	j;
	size_t	a_initial_size;
	int		current_nbr;
	int		nbr_of_bits;

	nbr_of_bits = get_nbr_of_bits(a);
	a_initial_size = a->size;
	i = 0;
	while (i < nbr_of_bits)
	{
		j = 0;
		while (j < a_initial_size)
		{
			current_nbr = get_from_stack(0, a);
			if (((current_nbr >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

static int	get_nbr_of_bits(t_stack *a)
{
	int	largest_nbr;
	int	nbr_of_bits;

	largest_nbr = a->size - 1;
	nbr_of_bits = 0;
	while (largest_nbr > 0)
	{
		largest_nbr >>= 1;
		nbr_of_bits++;
	}
	return (nbr_of_bits);
}
