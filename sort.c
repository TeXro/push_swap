/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:15:35 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:19:11 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_sort(t_list **stack_a, t_list **stackb)
{
	t_list *num;

	num = *stack_a;
	while (num->next)
	{
		if (num->data > num->next->data)
		{
			ra(stack_a);
			sa(stack_a);
			printf("not sorted");
			return;
		}
		
		num = num->next;
	}
}
