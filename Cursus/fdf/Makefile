# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 12:45:08 by gamado-x          #+#    #+#              #
#    Updated: 2023/11/08 16:19:30 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
SRCS_DIR	:= source-files
OBJS_DIR	:= objs
MLX_DIR		:= ./minilibx-linux
LIBFDF		:= fdf-lib
LIBMLX		:= ./minilibx-linux/libmlx.a
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS	:= -lmlx -lXext -lX11
AR		:= ar -crs
RM		:= rm -rf
SRCS		:= window.c image.c canvas.c main.c 
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) $(MLXFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(LIBFDF) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re





