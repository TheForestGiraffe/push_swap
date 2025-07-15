/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/15 20:48:25 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void    push(int nbr, t_stack *stack) //
{
    if (stack->size + 1 > stack->capacity)
        double_stack_capacity(stack);
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->buffer[stack->top] = nbr;
    stack->size++;
}
