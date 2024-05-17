
#include "ps_lib.h"

void	free_stack(t_list *a, t_list *b)
{
	t_list	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	while (b)
	{
		temp = b;
		b = b->next;
		free(temp);
	}
}

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

t_list	*list_insertion(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	while (--argc > 0)
		node_insertion(&stack, ft_atoi(argv[argc]));
	return (stack);
}
