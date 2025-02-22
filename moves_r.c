/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:36 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:18:27 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **stack_a)
{
    t_list *first;
    t_list *last;

    if (!*stack_a || !(*stack_a)->next)
        return;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void rb(t_list **stackb)
{
    t_list *first;
    t_list *last;

    if (!*stackb || !(*stackb)->next)
        return;
    first = *stackb;
    *stackb = (*stackb)->next;
    last = *stackb;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void rr(t_list **stack_a, t_list **stackb)
{
    ra(stack_a);
    rb(stackb);
}
