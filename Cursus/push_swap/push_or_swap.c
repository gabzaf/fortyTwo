/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_or_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:46:27 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 16:03:02 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

static void     push_instruction(t_stack **src, t_stack **dst);
static void     swap_instruction(t_stack **stack);

static void     swap_instruction(t_stack **stack)
{
        t_stack *temp;
        t_stack *swap;

        if (*stack == NULL || (*stack)->next == NULL)
                return ;
        temp = *stack;
        swap = (*stack)->next;
        if (swap->next)
                swap->next->prev = *stack;
        swap->prev = temp->prev;
        temp->prev = swap;
        (*stack)->next = swap->next;
        swap->next = temp;
        *stack = swap;
}

void    swap(t_stack **a, t_stack **b, int instruction, t_push *st)
{
        if (a == NULL && b == NULL)
                return ;
        if (instruction == SA || instruction == SS)
                swap_instruction(a);
        if (instruction == SB || instruction == SS)
                swap_instruction(b);
        if (st->checker)
                return ;
        if (instruction == SA)
                write(1, "sa\n", 3);
        if (instruction == SB)
                write(1, "sb\n", 3);
        if (instruction == SS)
                write(1, "ss\n", 3);
}

static void     push_instruction(t_stack **src, t_stack **dst)
{
        t_stack *temp_src;
        t_stack *temp_dst;

        if (*src == NULL)
                return ;
        temp_src = *src;
        temp_dst = *dst;
        *src = temp_src->next;
        if (*src)
                (*src)->prev = NULL;
        if (temp_dst == NULL)
        {
                temp_src->next = NULL;
                *dst = temp_src;
                (*dst)->prev = NULL;
                return ;
        }
	temp_src->next = temp_dst;
        temp_dst->prev = temp_src;
        *dst = temp_src;
}

void	push(t_stack **a, t_stack **b, int instruction, t_push *st)
{
	if (instruction == PB)
	{
		push_instruction(a, b);
		st->size_of_a++;
                st->size_of_b--;
	}
	if (instruction == PA)
        {
                push_instruction(b, a);
                st->size_of_a++;
                st->size_of_b--;
        }
	if (st->checker)
                return ;
        if (instruction == PB)
                write(1, "pb\n", 3);
        if (instruction == PA)
                write(1, "pa\n", 3);
}
