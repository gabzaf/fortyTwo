# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 19:55:32 by gamado-x          #+#    #+#              #
#    Updated: 2023/05/21 16:34:37 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME	:= libft.a
CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
AR	:= ar -crs
RM	:= rm -rf
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c\
	  ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c\
	  ft_bzero.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c\
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c ft_split.c ft_itoa.c
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	     ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
