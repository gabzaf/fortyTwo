# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:45:51 by gamado-x          #+#    #+#              #
#    Updated: 2024/04/25 19:54:14 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM		:= rm -rf
SRCS		:= main.c ft_printf.c ft_printf_utils.c ft_pointer_printer.c ft_strlen.c ft_atoi.c ft_isdigit.c check_input.c 
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
