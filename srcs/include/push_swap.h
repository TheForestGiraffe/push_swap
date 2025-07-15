/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:44 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/15 20:48:01 by pecavalc         ###   ########.fr       */
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
void    push(int nbr, t_stack *stack);

// Error handling
void    print_error_and_exit(void);

// For unit tests TODO: remove
void	print_stack(t_stack *stack, char *name);

#endif
