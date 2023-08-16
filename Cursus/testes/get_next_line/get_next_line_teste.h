#ifndef GET_NEXT_LINE_TESTE_H
# define GET_NEXT_LINE_TESTE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	char			*string_buffer;
	struct s_list	*next;
}				t_list;
t_list  *find_last_node(t_list *list);

#endif
