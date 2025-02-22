/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:42:01 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:18:27 by zzin             ###   ########.fr       */
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
}

void rrb(t_list **stackb)
{
    t_list *last;
    t_list *second_last;

    if (!*stackb || !(*stackb)->next)
        return;
    last = *stackb;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stackb;
    *stackb = last;
}

void rrr(t_list **stack_a, t_list **stackb)
{
    rra(stack_a);
    rrb(stackb);
}
