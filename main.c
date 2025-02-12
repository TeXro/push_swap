/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:05 by zzin              #+#    #+#             */
/*   Updated: 2025/02/12 22:22:22 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_node(t_list **stack, int num)
{
	t_list	*tmp;
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return ;
	node->data = num;
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

int	handle_arg(char **arg, t_list **stack)
{
	int	i;
	int	a;
	int	*sp_arg;

	i = 0;
	while (arg[i])
	{
		sp_arg = ft_int_split(arg[i]);
		a = 0;
		while (sp_arg[a])
		{
			new_node(stack, sp_arg[a]);
			a++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	t_list	*currenta;
	t_list	*currentb;

	if (argc == 1)
		return (0);
	argv += 1;
	stacka = NULL;
	stackb = NULL;
	if (check_arg(argv) == 1)
		return (ft_error());
	handle_arg(argv, &stacka);
	handle_arg(argv, &stackb);
	currenta = stacka;
	currentb = stackb;
	printf("<A>\t<B>\n");
	while (currenta || currentb)
	{
		if (currenta)
		{
			printf("[%d]\t", currenta->data);
			currenta = currenta->next;
		}
		if (currentb)
		{
			printf("[%d]\t", currentb->data);
			currentb = currentb->next;
		}
		printf("\n");
	}
}
