
#include "ps_lib.h"

int	smallest_nbr(t_list *stack)
{
	int	smallest;

	smallest = stack->value;
	while ((stack->next) != NULL)
	{
		if (smallest > (stack->next->value))
			smallest = stack->next->value;
		stack = stack->next;
	}
	return (smallest);
}

void	five_items(t_list **a, t_list **b)
{
	int	smallest;
	t_list	*head;

	head = *a;
	smallest = smallest_nbr(head);
	if ((*a)->next->value == smallest)
		swap_a(a);
	else if ((*a)->next->next->value == smallest)
	{
		rotate_a(a);
		rotate_a(a);
	}
	else if ((*a)->next->next->next->value == smallest)
	{
		reverse_a(a);
		reverse_a(a);
	}
	else if ((*a)->next->next->next->next->value == smallest)
		reverse_a(a);
	push_b(a, b);
	four_items(a, b);
	push_a(a, b);
}

void	four_items(t_list **a, t_list **b)
{
	int	smallest;
	t_list	*head;

	head = *a;
	smallest = smallest_nbr(head);
	if ((*a)->next->value == smallest)
		swap_a(a);
	else if ((*a)->next->next->value == smallest)
	{
		reverse_a(a);
		reverse_a(a);
	}
	else if ((*a)->next->next->next->value == smallest)
		reverse_a(a);
	push_b(a, b);
	three_items(a);
	push_a(a, b);
}

void	three_items(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if ((first < second) && (second > third) && (first < third))
	{
		swap_a(a);
		rotate_a(a);
	}
	else if ((first > second) && (second < third) && (first < third))
		swap_a(a);
	else if ((first < second) && (second > third) && (first > third))
		reverse_a(a);
	else if ((first > second) && (second < third) && (first > third))
		rotate_a(a);
	else if ((first > second) && (second > third) && (first > third))
	{
		swap_a(a);
		reverse_a(a);
	}
}

void	push_swap(int *array, t_list **a, t_list **b)
{
	int	len;

	len = stack_len(*a);
	if (!sort_check(*a))
	{
		if (len == 2)
			swap_a(a);
		else if (len == 3)
			three_items(a);
		else if (len == 4)
			four_items(a, b);
		else if (len ==5)
			five_items(a, b);
		else
			radix_sort(array, a, b);
	}
}
