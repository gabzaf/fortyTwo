# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 12:45:08 by gamado-x          #+#    #+#              #
#    Updated: 2023/12/07 19:09:01 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
SRCS_DIR	:= source-files
OBJS_DIR	:= objs
MLX_DIR		:= ./minilibx-linux
LIBFDF		:= fdf-lib
LIBMLX		:= ./minilibx-linux/libmlx.a
LIBGNL		:= ./gnl-lib
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS	:= -lmlx -lXext -lX11 -lm -lbsd
AR		:= ar -crs
RM		:= rm -rf
SRCS		:= get_next_line.c get_next_line_utils.c ft_nbr_counter.c file_reader.c draw.c ft_split.c ft_atoi.c ft_handle_errors.c isometric.c draw_utils.c main.c 
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) $(MLXFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(LIBFDF) -I $(LIBGNL) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re





