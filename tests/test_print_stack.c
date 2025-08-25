/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:05:50 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/25 23:38:43 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	print_stack(t_stack *stack, char *name)
{
	size_t	i;

    i = 0;
    while (i < stack->size)
        printf("%i\n", stack->buffer[(stack->top + i++) % stack->capacity]);
    printf("%s size: %zu\n", name, stack->size);
	printf("%s capacity: %zu\n", name, stack->capacity);
}