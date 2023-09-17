# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:55:32 by gamado-x          #+#    #+#              #
#    Updated: 2023/09/17 12:10:56 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME	:= libftprintf.a
CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
AR	:= ar -crs
RM	:= rm -rf
SRCS	= ft_strlen.c ft_printf_utils.c ft_pointer_printer.c ft_printf.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
