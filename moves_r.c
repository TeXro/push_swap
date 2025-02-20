/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:36 by zzin              #+#    #+#             */
/*   Updated: 2025/02/20 20:55:37 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **stacka)
{
    t_list *first;
    t_list *last;

    if (!*stacka || !(*stacka)->next)
        return;
    first = *stacka;
    *stacka = (*stacka)->next;
    last = *stacka;
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

void rr(t_list **stacka, t_list **stackb)
{
    ra(stacka);
    rb(stackb);
}
