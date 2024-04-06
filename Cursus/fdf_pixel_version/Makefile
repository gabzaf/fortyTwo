# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 12:45:08 by gamado-x          #+#    #+#              #
#    Updated: 2024/04/05 17:37:24 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf
SRCS_DIR	:= src
OBJS_DIR	:= objs
MLX_REP		:= minilibx-linux
LIBFDF		:= fdf-lib
MLXLIB		:= minilib-linux/libmlx_Linux.a
LIBGNL		:= ./gnl-lib
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS	:= -lmlx -lXext -lX11 -lm -lbsd
AR		:= ar -crs
RM		:= rm -rf
SRCS		:= get_next_line.c get_next_line_utils.c ft_nbr_counter.c file_reader.c draw.c ft_split.c ft_atoi.c ft_handle_errors.c isometric.c draw_utils.c main.c 
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_REP) $(MLXFLAGS) -o $(NAME)

$(MLXLIB): $(MLX_REP)
	@rm -rf minilib-linux/.git
	$(MAKE) -C $(MLX_REP)

$(MLX_REP): 
	@git clone git@github.com:42Paris/minilibx-linux.git

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -I $(LIBFDF) -I $(LIBGNL) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re





