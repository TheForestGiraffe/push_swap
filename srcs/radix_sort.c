/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:25:43 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 18:35:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include "libft.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	if (!a || !b)
		free_stacks_print_error_and_exit(a, b);
	index_stack(a, b);
	
}

void	index_stack(t_stack *a, t_stack *b)
{
	int	*a_copy;
	int	*a_copy_sorted;
	int	*a_copy_sorted_ranks;
	int	i;
	int j;
	
	// copy a->buffer
	a_copy = (int *)malloc(a->size * sizeof(int));
	if (!a_copy)
		free_stacks_print_error_and_exit(a, b);
	i = 0;
	while (i < a->size)
	{
		a_copy[i] = get_from_stack(i, a);
		i++;
	}
	
	// create sorted copy
	a_copy_sorted = (int *)malloc(a->size * sizeof(int));
	ft_memcpy(a_copy_sorted, a_copy, a->size);
	quicksort(a_copy_sorted, 0, a->size - 1);

	// TODO: test
	i = 0;
	j = 0;
	while (i < a->size)
	{
		if (a_copy[i] == a_copy_sorted[i + j])
		{
			a_copy_sorted_ranks[i] = i + j; 
			j = 0;
			i++;
		}
		else
			j++;
	}
	
	// TODO: 
	//	- Overwritte stack with indices / create parallel stacks?
	// 	- Free temporary arrays
}

