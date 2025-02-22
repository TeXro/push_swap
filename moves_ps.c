/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:40:21 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:34:09 by zzin             ###   ########.fr       */
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
	write(1, "sa\n", 3);
}

void sb(t_list **stack_b)
{
	t_list *first;
	t_list *second;

	if (!(*stack_b)->next)
		return ;	
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	*stack_b = second;
	(*stack_b)->next = first;
	write(1, "sb\n", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
	write(1, "ss\n", 3);
}

void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
	write(1, "pa\n", 3);
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (!*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
	write(1, "pb\n", 3);
}
