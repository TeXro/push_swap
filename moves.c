/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:35 by zzin              #+#    #+#             */
/*   Updated: 2025/02/12 17:11:45 by zzin             ###   ########.fr       */
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
