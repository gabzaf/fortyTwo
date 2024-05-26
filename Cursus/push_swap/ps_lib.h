/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:10 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 15:07:19 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIB_H
# define PS_LIB_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_push
{
	bool		error;
	bool		checker;
	int			rotate[6];
	int			size_of_a;
	int			size_of_b;
}					t_push;

enum e_instruction
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
        PB	
};

char	**ft_split(char const *str, char c);
void	initialize_stack(int argc, char **argv, t_stack **a, t_push *st);
void	ft_isdigit(char *str, t_push *st);
void	ft_free_split(char **tab);
bool	ft_lstsorted(t_stack *stack);
void	sorting(t_stack **a, t_stack **b, t_push *st);
void    sort_three_items(t_stack **a, t_stack **b, t_push *st);
void	push(t_stack **a, t_stack **b, int instruction, t_push *st);
void    get_move(t_stack **a, t_stack **b, t_push *st, int stack);
void    swap(t_stack **a, t_stack **b, int instruction, t_push *st);
t_stack *ft_lstlast(t_stack *stack);
int     	get_smallest(t_stack *stack);
int     	get_biggest(t_stack *stack);
void    rotate(t_stack **a, t_stack **b, int instruction, t_push *st);
void    reverse(t_stack **a, t_stack **b, int instruction, t_push *st);
void    ft_clean(t_stack **a, t_stack **b, t_push *st);

#endif
