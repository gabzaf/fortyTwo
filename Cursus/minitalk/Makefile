# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 16:45:30 by gamado-x          #+#    #+#              #
#    Updated: 2023/10/05 18:21:50 by gamado-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror
CLIENTSRCS	:= client.c ft_strlen.c
SERVERSRCS	:= server.c 
CLIENTOBJS	:= $(CLIENTSRCS:.c=.o)
SERVEROBJS	:= $(SERVERSRCS:.c=.o)

all: client server

client: $(CLIENTOBJS)
	$(CC) $(CFLAGS) -o client $(CLIENTOBJS)

server: $(SERVEROBJS)
	$(CC) $(CFLAGS) -o server $(SERVEROBJS)

clean:
	$(RM) $(CLIENTOBJS) $(SERVEROBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

