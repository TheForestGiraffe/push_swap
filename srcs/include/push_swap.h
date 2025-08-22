/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/21 11:41:57 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INITIAL_CAPACITY 2

# include <stdlib.h>

typedef struct s_stack {
    size_t  capacity;
    size_t  size;
    size_t  top;
    int     *buffer;
}           t_stack;

// Input parsing and validation
void	parse_and_validate_input(int argc, char **argv, t_stack *a);

// Stack management
void    initialize_stack(t_stack *stack, size_t capacity, t_stack *other_stack);
void    double_stack_capacity(t_stack *stack);
void	free_stacks(t_stack *a, t_stack *b);

// Stack operations - standard
int		get_from_stack(size_t position, t_stack *stack);
int		is_in_stack(t_stack *stack, int nbr);
int		pop_from_stack(t_stack *stack);

// Stack operations - standard continued
void    add_to_stack(int nbr, t_stack *stack);
void    push_to_stack(int nbr, t_stack *stack);
void	set_all_in_stack(t_stack *a, int *a_copy_sorted_ranks);
void	swap_in_stack(t_stack *stack);

// Stack operations - push_swap
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ra(t_stack *a);

// Stack operations - push_swap continued
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Sorting of small stacks of size < 4
void	sort_two_numbers(t_stack *a, t_stack *b);
void	sort_three_numbers(t_stack *a, t_stack *b);

// Stack indexing for Radix sort
void	quicksort(int *array, int start, int end);
void	index_stack(t_stack *a, t_stack *b);

// Sorting of stacks of size > 3
void	radix_sort(t_stack *a, t_stack *b);

// Error printing, exiting and cleanup
void    print_error_and_exit(void);
void	free_stacks_print_error_and_exit(t_stack *a, t_stack *b);

// For unit tests TODO: remove
void	print_stack(t_stack *stack, char *name);

#endif
