/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:30:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/26 15:30:05 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static int	partition(int *array, int start, int end);

void	quicksort(int *array, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = partition(array, start, end);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, end);
}

static int	partition(int *array, int start, int end)
{
	int	j;
	int	i;
	int	temp;

	j = start;
	i = start -1;
	while (j <= end)
	{
		if (array[j] <= array[end])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		j++;
	}
	return (i);
}
