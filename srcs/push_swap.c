/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 23:31:22 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc == 1)
        return (0);
    initialize_stack(&a, INITIAL_CAPACITY, &b);
    parse_and_validate_input(argc, argv, &a);
	initialize_stack(&b, a.capacity, &a);
	if (a.size == 2)
		sort_two_numbers(&a, &b);
	if (a.size == 3)
		sort_three_numbers(&a, &b);
	if (a.size == 4 || a.size == 5)
		sort_four_to_five_numbers(&a, &b);
	if (a.size > 5 && !is_sorted(&a))
	{
		index_stack(&a, &b);
		radix_sort(&a,&b);
	}
	free_stacks(&a, &b);
    return (EXIT_SUCCESS);
}
