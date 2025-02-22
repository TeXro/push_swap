/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:40:21 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:18:27 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **stack_a)
{
	t_list *first;
	t_list *second;

	if (!(*stack_a)->next)
		return ;	
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	*stack_a = second;
	(*stack_a)->next = first;
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

void ss(t_list **stack_a, t_list **stackb)
{
    sa(stack_a);
    sb(stackb);
}

void pa(t_list **stack_a, t_list **stackb)
{
    t_list *tmp;

    if (!*stackb)
        return;
    tmp = *stackb;
    *stackb = (*stackb)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void pb(t_list **stack_a, t_list **stackb)
{
    t_list *tmp;

    if (!*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stackb;
    *stackb = tmp;
}
