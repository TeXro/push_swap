/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:35 by zzin              #+#    #+#             */
/*   Updated: 2025/02/18 14:46:41 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stacka)
{
	t_list *first;
	t_list *second;

	if (!(*stacka)->next)
		return ;	
	first = *stacka;
	second = (*stacka)->next;
	first->next = second->next;
	*stacka = second;
	(*stacka)->next = first;
}

void sb(t_list **stackb)
{
	t_list *first;
	t_list *second;

	if (!(*stackb)->next)
		return ;	
	first = *stackb;
	second = (*stackb)->next;
	first->next = second->next;
	*stackb = second;
	(*stackb)->next = first;
}

void ss(t_list **stacka, t_list **stackb)
{
    sa(stacka);
    sb(stackb);
}

void pa(t_list **stacka, t_list **stackb)
{
    t_list *tmp;

    if (!*stackb)
        return;
    tmp = *stackb;
    *stackb = (*stackb)->next;
    tmp->next = *stacka;
    *stacka = tmp;
}

void pb(t_list **stacka, t_list **stackb)
{
    t_list *tmp;

    if (!*stacka)
        return;
    tmp = *stacka;
    *stacka = (*stacka)->next;
    tmp->next = *stackb;
    *stackb = tmp;
}

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