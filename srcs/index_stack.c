/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:25:43 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 23:27:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include "libft.h"

static int	*copy_stack_to_new_array(t_stack *stack);
static int	*copy_to_new_sorted_array(int *array, size_t size);
static int	*array_to_ranks(int *a_copy, int *a_copy_sorted, size_t size);
static void	free_arrays(int *array_1, int *array_2, int *array_3);

void	index_stack(t_stack *a, t_stack *b)
{
	int		*a_copy;
	int		*a_copy_sorted;
	int		*sorted_ranks;

	if (!a || !b)
	free_stacks_print_error_and_exit(a, b);
	a_copy = copy_stack_to_new_array(a);
	if (!a_copy)
		free_stacks_print_error_and_exit(a, b);
	a_copy_sorted = copy_to_new_sorted_array(a_copy, a->size);
	if (!a_copy_sorted)
	{
		free_arrays(a_copy, NULL, NULL);
		free_stacks_print_error_and_exit(a, b);
	}
	sorted_ranks = array_to_ranks(a_copy, a_copy_sorted, a->size);
	if (!sorted_ranks)
	{
		free_arrays(a_copy, a_copy_sorted, NULL);
		free_stacks_print_error_and_exit(a, b);
	}
	set_all_in_stack(a, sorted_ranks);
	free_arrays(a_copy, a_copy_sorted, sorted_ranks);
}
static int	*copy_stack_to_new_array(t_stack *stack)
{
	int		*copy;
	size_t	i;

	copy = (int *)malloc(stack->size * sizeof(int));
	i = 0;
	while (i < stack->size)
	{
		copy[i] = get_from_stack(i, stack);
		i++;
	}
	return (copy);
}

static int	*copy_to_new_sorted_array(int *array, size_t size)
{
	int	*sorted_copy;

	sorted_copy = (int *)malloc(size * sizeof(int));
	ft_memcpy(sorted_copy, array, size * sizeof(int));
	quicksort(sorted_copy, 0, size - 1);
	return (sorted_copy);
}

static int	*array_to_ranks(int *a_copy, int *a_copy_sorted, size_t size)
{
	int		*sorted_ranks;
	size_t	i;
	size_t	j;

	sorted_ranks = (int *)malloc(size * sizeof(int));
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a_copy[i] == a_copy_sorted[j])
			{
				sorted_ranks[i] = j; 
				break;
			}
			j++;
		}
		i++;
	}
	return (sorted_ranks);
}
static void	free_arrays(int *array_1, int *array_2, int *array_3)
{
	free(array_1);
	free(array_2);
	free(array_3);
}
