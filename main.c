/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:05 by zzin              #+#    #+#             */
/*   Updated: 2025/02/11 22:47:41 by zzin             ###   ########.fr       */
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
		sp_arg = ft_int_split(arg[i], ' ');
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
	t_list	*currenta;

	if (argc == 1)
		return (ft_error());
	argv += 1;
	stacka = NULL;
	if (repeat(argv) == 1)
		return (ft_error());
	if (check_arg(argv) == 1)
		return (ft_error());
	handle_arg(argv, &stacka);
	currenta = stacka;
	printf("<stackA>\n");
	while (currenta)
	{
		printf("[%d]\n", currenta->data);
		currenta = currenta->next;
	}
}
