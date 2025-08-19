/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 17:33:42 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void    print_error_and_exit()
{
  ft_putstr_fd("Error\n", 2);
  exit(EXIT_FAILURE);
}

void	free_stacks_print_error_and_exit(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	print_error_and_exit();
}
