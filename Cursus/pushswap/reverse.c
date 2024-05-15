
#include "ps_lib.h"

void	ft_reverse(t_list *stack)
{
	t_list	*tail;
	t_list	*prev;

	if (stack == NULL || stack->next == NULL)
		return ;
	tail = stack;
	prev = NULL;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = stack;
	prev->next = NULL;
	stack = tail;
}

void	reverse_b(t_list *b)
{
	ft_reverse(b);
	ft_printf("rrb\n");
}

void	reverse_a(t_list *a)
{
	ft_reverse(a);
	ft_printf("rra\n");
}
