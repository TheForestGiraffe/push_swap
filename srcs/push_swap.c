/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/11 14:01:14 by pecavalc         ###   ########.fr       */
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
    parse_and_validate_input(argc, argv, &a);
	initialize_stack(&b, a.capacity);
	
	// sort

	// TODO: test prints, remove
	print_stack(&a, "Stack a");
	print_stack(&b, "Stack b");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	print_stack(&a, "Stack a");
	print_stack(&b, "Stack b");
	rr(&a, &b);
	rr(&a, &b);
	rr(&a, &b);
	print_stack(&a, "Stack a");
	print_stack(&b, "Stack b");
	rrr(&a, &b);
	rrr(&a, &b);
	rrr(&a, &b);
	print_stack(&a, "Stack a");
	print_stack(&b, "Stack b");

	free_stacks(&a, &b);

    return (EXIT_SUCCESS);
}
