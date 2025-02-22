/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:26:50 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 07:12:51 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_node(t_list **stack, long data)
{
	t_list	*tmp;
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = data;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	sorted_check(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	len_stack(t_list **stack_a)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = *stack_a;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	sort_in_table(int *table, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (table[j] > table[j + 1])
			{
				tmp = table[j + 1];
				table[j + 1] = table[j];
				table[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
