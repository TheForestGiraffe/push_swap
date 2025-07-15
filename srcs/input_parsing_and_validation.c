/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing_and_validation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:44:32 by pecavalc          #+#    #+#             */
/*   Updated: 2025/07/15 20:48:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

void	parse_and_validate_input(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	char	**split_str;
	
    i = 1;
    while (i < argc)
    {
        split_str = ft_split(argv[i++], ' ');
        if (!split_str)
            print_error_and_exit();
        j = 0;
        while (split_str[j])
            push(ft_atoi(split_str[j++]), a); // TODO: Add safeguards to atoi or write and use strtol instead
        free(split_str);
    }
}
