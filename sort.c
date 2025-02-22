/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:15:35 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:53:27 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (a > c && b < c)
		ra(stack_a);
	else if (a > c && a > b && b > c)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (b > a && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && a < c)
		sa(stack_a);
}

void	push_help(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	len;

	len = len_stack(stack_a);
	if (pos <= (len / 2))
	{
		while (pos--)
			ra(stack_a);
	}
	else
	{
		while (pos++ < len)
			rra(stack_a);
	}
	if (!sorted_check(stack_a))
		return ;
	pb(stack_a, stack_b);
}

void	push_s_t_b(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;
	int		pos;
	int		i;

	i = 1;
	tmp = *stack_a;
	min = (*stack_a)->num;
	pos = 0;
	while (tmp && tmp->next)
	{
		if (min > tmp->next->num)
		{
			min = tmp->next->num;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	push_help(stack_a, stack_b, pos);
}

void	small_sort(t_stack **stack_a, int len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (len == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
	}
	else if (len == 3)
		three_sort(stack_a);
	else
	{
		if (len == 4)
			push_s_t_b(stack_a, &stack_b);
		else if (len == 5)
		{
			push_s_t_b(stack_a, &stack_b);
			push_s_t_b(stack_a, &stack_b);
		}
		three_sort(stack_a);
		pa(stack_a, &stack_b);
		pa(stack_a, &stack_b);
	}
}

void	sort_stack(t_stack **stack_a, int len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (len == 1)
		return ;
	if (len <= 5)
		small_sort(stack_a, len);
	else if (len > 5)
		big_sort(stack_a, &stack_b, len);
}
