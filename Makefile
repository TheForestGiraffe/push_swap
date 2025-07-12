# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 18:03:57 by pecavalc          #+#    #+#              #
#    Updated: 2025/07/12 22:02:16 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
	
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =  push_swap.c
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

HEADERS_DIR = srcs/include
HEADERS = $(HEADERS_DIR)/push_swap.h

LIBFT_DIR = ../Libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include
LIBFT_HEADERS = $(LIBFT_HEADERS_DIR)/libft.h $(LIBFT_HEADERS_DIR)/libft_bonus.h

CFLAGS = -Wall -Wextra -Werror -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR)

GREEN = \033[0;32m

all: $(NAME)
	@echo "$(GREEN)Build successful $(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) -o $@ $^ 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) bonus -C ../Libft

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re