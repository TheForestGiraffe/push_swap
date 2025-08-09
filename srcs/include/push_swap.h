/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/08/09 22:21:13 by pecavalc         ###   ########.fr       */
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
void    initialize_stack(t_stack *stack, size_t capacity);
void    double_stack_capacity(t_stack *stack);
void	free_stacks(t_stack *a, t_stack *b);

// Stack operations 
int		read_from_stack(size_t position, t_stack *stack);
int		is_in_stack(t_stack *stack, int nbr);
int		pop_from_stack(t_stack *stack);
void    add_to_stack(int nbr, t_stack *stack);
void    push_to_stack(int nbr, t_stack *stack);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	swap_in_stack(t_stack *stack);
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);

// Error handling
void    print_error_and_exit(void);

// For unit tests TODO: remove
void	print_stack(t_stack *stack, char *name);

#endif
