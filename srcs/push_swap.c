/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/15 21:18:22 by pecavalc         ###   ########.fr       */
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
    initialize_stack(&a, INITIAL_CAPACITY);
    parse_and_validate_input(argc, argv, &a); // TODO: further validation checks
	initialize_stack(&b, a.capacity);
	
	// sort

	// test prints
	print_stack(&a, "Stack a");
	print_stack(&b, "Stack b");

	free_stacks(&a, &b);

    return (EXIT_SUCCESS);
}
