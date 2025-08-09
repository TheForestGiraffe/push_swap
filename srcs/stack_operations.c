/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:57:16 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/09 22:38:35 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

int	is_in_stack(t_stack *stack, int nbr)
{
	size_t	position;

	position = 0;
	while (position < stack->size)
	{
		if (nbr == read_from_stack(position++, stack))
			return (1);
	}
	return (0);
}

int	read_from_stack(size_t position, t_stack *stack)
{
	size_t	i;

	i = (stack->top + position) % stack->capacity;
	return (stack->buffer[i]);
}

void    push_to_stack(int nbr, t_stack *stack)
{
    stack->top = (stack->top - 1 + stack->capacity) % stack->capacity;
    stack->buffer[stack->top] = nbr;
    stack->size++;
}

void    add_to_stack(int nbr, t_stack *stack)
{
    if (stack->size + 1 > stack->capacity)
        double_stack_capacity(stack);
    stack->buffer[(stack->top + stack->size) % stack->capacity] = nbr;
    stack->size++;
}

int	pop_from_stack(t_stack *stack)
{
	int	nbr;
	
	nbr = stack->buffer[stack->top];
	stack->top = (stack->top + 1) % stack->capacity;
	stack->size--;
	return (nbr);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0 || b->size + 1 > b->capacity)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	push_to_stack(pop_from_stack(a), b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0 || a->size + 1 > a->capacity)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	push_to_stack(pop_from_stack(b), a);
	ft_putstr_fd("pa\n", 1);
}

void	swap_in_stack(t_stack *stack)
{
	int	temp;

	temp = stack->buffer[stack->top];
	stack->buffer[stack->top] = stack->buffer[(stack->top + 1) % stack->capacity];
	stack->buffer[(stack->top + 1) % stack->capacity] = temp;
}

void	sa(t_stack *a, t_stack *b)
{
	if (a->size < 2)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	swap_in_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *a, t_stack *b)
{
	if (b->size < 2)
	{
		free_stacks(a, b);
		print_error_and_exit();
	}
	swap_in_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	a->buffer[(a->top + a->size) % a->capacity] = a->buffer[a->top];
	a->top = (a->top + 1) % a->capacity;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	b->buffer[(b->top + b->size) % b->capacity] = b->buffer[b->top];
	b->top = (b->top + 1) % b->capacity;
	ft_putstr_fd("rb\n", 1);
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

