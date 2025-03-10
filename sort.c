/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 04:15:35 by zzin              #+#    #+#             */
/*   Updated: 2025/02/24 18:06:52 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
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

void	push_help(t_list **stack_a, t_list **stack_b, int pos)
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

void	push_s_t_b(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;
	int		pos;
	int		i;

	i = 1;
	tmp = *stack_a;
	min = (*stack_a)->data;
	pos = 0;
	while (tmp && tmp->next)
	{
		if (min > tmp->next->data)
		{
			min = tmp->next->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	printf("(pos=%d)(i=%d)\n", pos, i);
	push_help(stack_a, stack_b, pos);
}

void	small_sort(t_list **stack_a, int len)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (len == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
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

void one_move(t_list **stack_a)
{

}

int require_one(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	tmp = tmp->next;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return 1;
		tmp = tmp->next;
	}
	printf("req");
	return 0;
}

void	sort_stack(t_list **stack_a, int len)
{
	t_list	*stack_b;
	t_list	*curr;

	stack_b = NULL;
	curr = *stack_a;

	while (curr)
	{
		printf("->%ld\n", curr->data);
		curr = curr->next;
	}
	printf("op=====>\n");
	if (len == 1)
		return ;
	if (len <= 5)
		small_sort(stack_a, len);
	else if(!require_one(stack_a))
		sa(stack_a);
	else if (len > 5)
		big_sort(stack_a, &stack_b, len);
	curr = *stack_a;
	while (curr)
	{
		printf("->%ld\n", curr->data);
		curr = curr->next;
	}
	
}
