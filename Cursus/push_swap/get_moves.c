/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:04:31 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 15:03:17 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void     values_aux(t_push *st, int *rotate)
{
        if (rotate[RRA] > 0 && rotate[RRB] > 0)
        {
                while (rotate[RRA] && rotate[RRB])
                {
                        rotate[RRR]++;
                        rotate[RRA]--;
                        rotate[RRB]--;
                }
        }
        if (rotate[RA] + rotate[RB] + rotate[RRA] + rotate[RRB] \
                + rotate[RR] + rotate[RRR] < st->rotate[RA] + st->rotate[RB] \
                + st->rotate[RRA] + st->rotate[RRB] + st->rotate[RRR] + st->rotate[RR])
        {
                st->rotate[RA] = rotate[RA];
                st->rotate[RB] = rotate[RB];
                st->rotate[RR] = rotate[RR];
                st->rotate[RRA] = rotate[RRA];
                st->rotate[RRB] = rotate[RRB];
                st->rotate[RRR] = rotate[RRR];
        }
}

static void     set_values(t_push *st, int *rotate, bool init)
{
        if (init)
        {
                rotate[RA] = INT_MAX;
                rotate[RB] = INT_MAX;
                rotate[RRA] = INT_MAX;
                return ;
        }
        if (rotate[RA] == INT_MAX)
                rotate[RA] = 0;
        if (rotate[RRA] == INT_MAX)
                rotate[RRA] = 0;
        if (rotate[RB] == INT_MAX)
                rotate[RB] = 0;
        if (rotate[RRB] == INT_MAX)
                rotate[RRB] = 0;
        if (rotate[RA] > 0 && rotate[RB] > 0)
        {
                while (rotate[RA] && rotate[RB])
                {
                        rotate[RR]++;
                        rotate[RA]--;
                        rotate[RB]--;
                }
        }
        values_aux(st, rotate);
}

static void     get_few_moves_to_b(t_stack **a, t_stack **b, t_push *st, t_stack *node)
{
        int             index;
        int             rotate[6];
        t_stack *temp;

        index = 0;
        rotate[RR] = 0;
        rotate[RRR] = 0;
        rotate[RRB] = INT_MAX;
        set_values(st, rotate, true);
        temp = *b;
        while (temp->value != node->value && index++ != -1)
                temp = temp->next;
        if (index > st->size_of_b / 2)
                rotate[RRB] = st->size_of_b - index;
        else
                rotate[RB] = index;
        index = 0;
        temp = *a;
        while (temp->value != node->index && index++ != -1)
                temp = temp->next;
        if (index > st->size_of_a / 2)
                rotate[RRA] = st->size_of_a - index;
        else
                rotate[RA] = index;
        return (set_values(st, rotate, false));
}

static void     get_few_moves_to_a(t_stack **a, t_stack **b, t_push *st, t_stack *node)
{
        int             index;
        int             rotate[6];
        t_stack *temp;

        index = 0;
        rotate[RR] = 0;
        rotate[RRR] = 0;
        rotate[RRB] = INT_MAX;
        set_values(st, rotate, true);
        temp = *a;
        while (temp->value != node->value && index++ != -1)
                temp = temp->next;
        if (index > st->size_of_a / 2)
                rotate[RRA] = st->size_of_a - index;
        else
                rotate[RA] = index;
        index = 0;
        temp = *b;
        while (temp->value != node->index && index++ != -1)
                temp = temp->next;
        if (index > st->size_of_b / 2)
                rotate[RRB] = st->size_of_b - index;
        else
                rotate[RB] = index;
}

void    get_move(t_stack **a, t_stack **b, t_push *st, int stack)
{
        t_stack *temp;

        temp = *b;
        if (stack == 'A')
                temp = *a;
        st->rotate[RA] = 100;
        st->rotate[RB] = 100;
        st->rotate[RR] = 100;
        st->rotate[RRA] = 100;
        st->rotate[RRB] = 100;
        st->rotate[RRR] = 100;
        while (temp != NULL)
        {
                if (stack == 'A')
                        get_few_moves_to_a(a, b, st, temp);
                else
                        get_few_moves_to_b(a, b, st, temp);
                temp = temp->next;
        }
}

