/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:03:02 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/14 17:00:58 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "include/push_swap.h"

int	*parse_input(int argc, char ***argv);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parse_input(argc, &argv);
	stack_b = init_stack();

	return (EXIT_SUCCESS);
}
/*
void	parse_input(int argc, char **argv)
{
	int		i;
	char	**strings;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	
	// for each argument
	//		split by spaces
	//		convert each string with atoi -> update it to 1. catch overflow and 2. exit on non-digit characters
	//		add number to stack, checking its capacitity. If reached, doublde the array size.
	//		free split
	//		increment argument

	// Initialize stack_a in the heap with calloc.
}
*/
