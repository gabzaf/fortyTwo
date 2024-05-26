/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:51:20 by gamado-x          #+#    #+#             */
/*   Updated: 2024/05/26 14:01:59 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

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
