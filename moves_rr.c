/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:42:01 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:34:09 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **stack_a)
{
    t_list *last;
    t_list *second_last;

    if (!*stack_a || !(*stack_a)->next)
        return;
    last = *stack_a;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
	write(1, "rra\n", 4);
}

void rrb(t_list **stack_b)
{
    t_list *last;
    t_list *second_last;

    if (!*stack_b || !(*stack_b)->next)
        return;
    last = *stack_b;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
	write(1, "rrb\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
	write(1, "rrr\n", 4);
}
