/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:41:36 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:34:09 by zzin             ###   ########.fr       */
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
	write(1, "ra\n", 3);
}

void rb(t_list **stack_b)
{
    t_list *first;
    t_list *last;

    if (!*stack_b || !(*stack_b)->next)
        return;
    first = *stack_b;
    *stack_b = (*stack_b)->next;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
	write(1, "rb\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
	write(1, "rr\n", 3);
}
