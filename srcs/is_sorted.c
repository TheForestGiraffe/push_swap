/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:00:05 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 23:27:59 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (get_from_stack(i, a) > get_from_stack(i + 1, a))
			return (0);
		i++;
	}
	return (1);
}
