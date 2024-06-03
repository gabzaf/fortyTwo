/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:10 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/31 10:20:50 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIB_H
# define PS_LIB_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_sort_state
{
	bool			error;
	bool			checker;
	int				rotate[6];
	int				a_len;
	int				b_len;
}	t_sort_state;

enum e_moves
{
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
	SA,
	SB,
	SS,
	PA,
	PB,
};

void			push(t_stack **a, t_stack **b, int instruction, \
				t_sort_state *st);
void			swap(t_stack **a, t_stack **b, int instruction, \
				t_sort_state *st);
void			rotate(t_stack **a, t_stack **b, int move, \
				t_sort_state *st);
void			reverse(t_stack **a, t_stack **b, int mv, \
				t_sort_state *st);
void			ft_free_split(char **split);
char			**ft_split(const char *s, char c);
void			ft_isdigit(char *str, t_sort_state *st);
void			initialize_stack(t_stack **a, int argc,	\
				char **argv, t_sort_state *st);
void			sorting(t_stack **a, t_stack **b, t_sort_state *st);
void			get_moves(t_stack **a, t_stack **b, t_sort_state *st, \
				int stack);
void			tiny_sort(t_stack **a, t_stack **b, t_sort_state *st);
t_stack			*ft_lstlast(t_stack *stack);
int				ft_biggest(t_stack *stack);
int				ft_smallest(t_stack *stack);
bool			ft_lstsorted(t_stack *stack);
void			ft_clean(t_stack **stack_a, t_stack **stack_b, \
				t_sort_state *st);
int				validation(char **argv);

#endif
