/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quicksort_arrray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:16:15 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 17:18:12 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "../../Libft/include/libft.h"

void	quicksort(int *array, int start, int end);

int	main(void)
{
	int	i;
	int	*array;
	int size;

	size = 8;
	array = (int *)malloc(size * sizeof(int));
	array[0] = 200;
	array[1] = -12;
	array[2] = 5;
	array[3] = -18;
	array[4] = INT_MIN;
	array[5] = INT_MAX;
	array[6] = 8344;
	array[7] = -82348;
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
	quicksort(array, 0, size - 1);
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	free(array);
	return (0);
}
