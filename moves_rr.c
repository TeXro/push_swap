/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:42:01 by zzin              #+#    #+#             */
/*   Updated: 2025/02/20 20:42:49 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **stacka)
{
    t_list *last;
    t_list *second_last;

    if (!*stacka || !(*stacka)->next)
        return;
    last = *stacka;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stacka;
    *stacka = last;
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

void rrr(t_list **stacka, t_list **stackb)
{
    rra(stacka);
    rrb(stackb);
}
