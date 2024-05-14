
#include "ps_lib.h"

void	node_insertion(t_list **head_node, int argv)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		exit(2);
	node->value = argv;
	node->next = *head_node;
	*head_node = node;
}

void	list_insertion(int argc, char **argv, t_list **a)
{
	while (--argc > 0)
		node_insertion(a, ft_atoi(argv[argc]));
}
