/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:10 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/24 20:58:21 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIB_H
# define PS_LIB_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				index_set;
	struct s_stack	*next;
}					t_stack;

int		check_dplctd_nbr(int argc, char **argv);
int		ft_strlen(const char *s);
int		check_input(int argc, char **argv);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	push_swap(t_stack **a, t_stack **b);
void	change(void (*op)(t_stack**), t_stack **head_node, char c);
t_stack	*node_gen(int value);
t_stack	*get_biggest(t_stack *stack);
int		asc_sort_check(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*get_tail(t_stack *stack);
t_stack	*get_last_before_tail(t_stack *stack);
void	big_sort_radix(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dst, char c);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);
void	three_items_sort(t_stack **a);
void	five_four_items_sort(t_stack **a, t_stack **b);
void	set_index(int len, t_stack **stack);
t_stack	*get_smallest(t_stack *stack);

#endif
