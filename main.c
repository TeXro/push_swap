/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:05 by zzin              #+#    #+#             */
/*   Updated: 2025/02/19 15:56:58 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_node(t_list **stack, long num)
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

int	nums(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}


int	handle_arg(char **arg, t_list **stack)
{
	int		i;
	int		a;
	int		lim;
	long	*sp_arg;

	i = 0;
	while (arg[i])
	{
		lim = nums(arg[i]);
		sp_arg = ft_int_split(arg[i]);
		a = 0;
		if (sp_arg == NULL)
			return (1);
		while (a < lim)
		{
			new_node(stack, sp_arg[a]);
			a++;
		}
		free(sp_arg);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*currenta;

	if (argc == 1)
		return (0);
	argv += 1;
	stacka = NULL;
	if (check_arg(argv))
		return (ft_error());
	if(handle_arg(argv, &stacka) == 1)
		return (ft_error());
	currenta = stacka;
	while (currenta)
	{
		printf("[%ld]\n", currenta->data);
		currenta = currenta->next;
	}
	free_list(stacka);
	return 0;
}
// int	main(int argc, char **argv)
// {
// 	t_list	*stacka;
// 	t_list	*stackb;
// 	t_list	*currenta;
// 	t_list	*currentb;

// 	if (argc == 1)
// 		return (0);
// 	argv += 1;
// 	stacka = NULL;
// 	stackb = NULL;
// 	if (check_arg(argv) == 1)
// 		return (ft_error());
// 	handle_arg(argv, &stacka);
// 	handle_arg(argv, &stackb);
// 	currenta = stacka;
// 	currentb = stackb;
// 	printf("<A>\t<B>\n");
// 	while (currenta || currentb)
// 	{
// 		if (currenta)
// 		{
// 			printf("[%d]\t", currenta->data);
// 			currenta = currenta->next;
// 		}
// 		if (currentb)
// 		{
// 			printf("[%d]\t", currentb->data);
// 			currentb = currentb->next;
// 		}
// 		printf("\n");
// 	}
// }