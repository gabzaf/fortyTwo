
#include "ps_lib.h"

void	items_push(t_list **a, t_list **b, int bit)
{
	int	nbr_to_push;
	int	len;

	nbr_to_push = 0;
	len = stack_len(*a);
	while (*a && len > 0)
	{
		if (!(*a)->index && bit)
		{
			push_b(a, b);
			nbr_to_push++;
		}
		else
			rotate_a(a);
		len--;
	}
	while (nbr_to_push > 0)
	{
		push_a(a, b);
		nbr_to_push--;
	}
}

void	index_set(int *array, t_list **a)
{
	int	i;
	t_list	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		if (temp->value == array[i])
		{
			temp->index = i;
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
}

void	radix_sort(int *array, t_list **a, t_list **b)
{
	int	bit;

	bit = 1;
	index_set(array, a);
	while (sort_check(*a) == 0)
	{
		items_push(a, b, bit);
		bit = bit << 1;
	}
}

