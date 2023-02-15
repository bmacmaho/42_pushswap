# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmacmaho <bmacmaho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 22:31:27 by bmacmaho          #+#    #+#              #
#    Updated: 2023/02/15 21:05:05 by bmacmaho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./src/0main.c ./src/1errors.c ./src/2prepstack.c ./src/3presort.c ./src/4send2b.c ./src/5back2a.c ./utils/utils.c ./utils/ops1.c ./utils/ops2.c 
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Werror -Wextra -Wall -g

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC ./includes/libft
	@$(CC) $(OBJS) $(CFLAGS) ./includes/libft/libft.a -o $(NAME)
	@echo "Created executable 'pushswap'\n"

clean:
	@make clean -sC ./includes/libft
	@echo "\nMade libft clean\n"
	@rm -rf $(OBJS)
	@echo "Removed object files\n"

fclean: clean
	@rm -rf $(NAME) ./includes/libft/libft.a
	@echo "Removed push_swap executable and libft.a\n"

re: fclean all
