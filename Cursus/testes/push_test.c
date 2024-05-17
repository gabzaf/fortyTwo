#include <stdio.h>


typedef struct	s_list
{
	int	value;
	struct s_list	*next;
}	t_list;

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

t_list	*list(int argc, char **argv)
{
	t_list	*stack;

	stack == NULL;
	while (--argc > 0)
		node_insertion(&stack, ft_atoi(argv[argc]);
				return (stack);
}

int	main(int argc, char **argv)
{
	t_list *a;

	a = NULL;
	if (argc >= 2)
	{
		a = list(argc, argv);
	}
	return (0);
}

