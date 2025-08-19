/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_push_swap_continued.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/19 23:49:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	b->buffer[(b->top + b->size) % b->capacity] = b->buffer[b->top];
	b->top = (b->top + 1) % b->capacity;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	a->buffer[(a->top + a->size) % a->capacity] = a->buffer[a->top];
	a->top = (a->top + 1) % a->capacity;
	b->buffer[(b->top + b->size) % b->capacity] = b->buffer[b->top];
	b->top = (b->top + 1) % b->capacity;
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *a)
{
	size_t	top_index;

	if (a->size < 2)
		return ;
    if (a->top == 0)
        top_index = a->capacity - 1;
    else
		top_index = a->top - 1;
	a->buffer[top_index] = a->buffer[(a->top + a->size - 1) % a->capacity];
	a->top = top_index;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	size_t	top_index;

	if (b->size < 2)
		return ;
	if (b->top == 0)
		top_index = b->capacity - 1;
	else
		top_index = b->top - 1;
	b->buffer[top_index] = b->buffer[(b->top + b->size - 1) % b->capacity];
	b->top = top_index;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	size_t	top_index;

	if (a->size < 2 || b->size < 2)
		return ;
    if (a->top == 0)
        top_index = a->capacity - 1;
    else
		top_index = a->top - 1;
	a->buffer[top_index] = a->buffer[(a->top + a->size - 1) % a->capacity];
	a->top = top_index;
	if (b->top == 0)
		top_index = b->capacity - 1;
	else
		top_index = b->top - 1;
	b->buffer[top_index] = b->buffer[(b->top + b->size - 1) % b->capacity];
	b->top = top_index;
	ft_putstr_fd("rrr\n", 1);
}
