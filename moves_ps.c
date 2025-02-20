/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:40:21 by zzin              #+#    #+#             */
/*   Updated: 2025/02/20 20:55:42 by zzin             ###   ########.fr       */
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
