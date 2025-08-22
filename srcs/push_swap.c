/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/22 16:51:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO: remove
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
	if (a.size > 3)
	{
		index_stack(&a, &b);
		radix_sort(&a,&b);
	}
	// Test print sorted stack
	//print_stack(&a, "a");
	free_stacks(&a, &b);

    return (EXIT_SUCCESS);
}
