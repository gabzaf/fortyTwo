# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:45:51 by gamado-x          #+#    #+#              #
#    Updated: 2024/05/24 21:02:37 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM		:= rm -rf
SRCS		:= main.c ft_strlen.c ft_atoi.c check_input.c ft_atol.c stack.c sorting.c sorting_utils.c push.c swap.c rotate.c reverse.c
OBJS		:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
