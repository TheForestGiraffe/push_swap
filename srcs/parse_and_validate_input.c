/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_validate_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:44:32 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/08 16:08:51 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "push_swap.h"

int		is_numeric_string(char *str);
int		is_in_stack(t_stack *stack, int nbr);
void	free_strings_array(char **strings_array);
void	free_strings_array_print_error_and_exit(char **strings_array);
int		push_swap_atoi(const char *str, char **strings_array);

void	parse_and_validate_input(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	int		nbr;
	char	**strings_array;

	i = 1;
	while (i < argc)
	{
		strings_array = ft_split(argv[i++], ' ');
		if (!strings_array)
			print_error_and_exit();
		j = 0;
		while (strings_array[j])
		{
			if (!is_numeric_string(strings_array[j]))
				free_strings_array_print_error_and_exit(strings_array);
			nbr = push_swap_atoi(strings_array[j++], strings_array);
			if (is_in_stack(a, nbr))
				free_strings_array_print_error_and_exit(strings_array);
			push_nbr_to_stack(nbr, a);
		}
		free_strings_array(strings_array);
	}
}

int	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	is_in_stack(t_stack *stack, int nbr)
{
	size_t	position;

	position = 0;
	while (position < stack->capacity)
	{
		if (nbr == get_nbr_from_stack(position++, stack))
			return (1);
	}
	return (0);
}

void	free_strings_array(char **strings_array)
{
	int	i;

	i = 0;
	while (strings_array[i])
		free(strings_array[i++]);
	free(strings_array);
}

void	free_strings_array_print_error_and_exit(char **strings_array)
{
	free_strings_array(strings_array);
	print_error_and_exit();
}

int	push_swap_atoi(const char *str, char **strings_array)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i++] - '0';
		if ((sign == 1 && nbr > INT_MAX) || (sign == -1 && (-nbr) < INT_MIN))
		{
			free_strings_array(strings_array);
			print_error_and_exit();
		}
	}
	return ((int)(nbr * sign));
}
