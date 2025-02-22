/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:34:05 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 07:20:59 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	*is_double(long *arr)
{
	static long	*joined;
	int			i;
	int			a;

	i = 0;
	if (!joined)
		joined = ft_long_join(NULL, arr);
	else
		joined = ft_long_join(joined, arr);
	while (joined[i] != 9999999999)
	{
		a = i + 1;
		while (joined[a] != 9999999999)
		{
			if (joined[i] == joined[a])
				return (free(joined), free(arr), NULL);
			a++;
		}
		i++;
	}
	return (joined);
}

int	handle_arg(char **arg, t_list **stack)
{
	int		i;
	int		a;
	long	*sp_arg;
	long	*join;

	i = 0;
	join = NULL;
	while (arg[i])
	{
		sp_arg = ft_int_split(arg[i]);
		if (sp_arg == NULL)
			return (free(join), 1);
		join = is_double(sp_arg);
		if (!join)
			return (free(join), 1);
		a = 0;
		while (sp_arg[a] != 9999999999)
			new_node(stack, sp_arg[a++]);
		free(sp_arg);
		i++;
	}
	return (free(join), 0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 1)
		return (0);
	argv += 1;
	stack_a = NULL;
	if (check_arg(argv))
		return (ft_error());
	if (handle_arg(argv, &stack_a) == 1)
	{
		if (stack_a)
			free_list(stack_a);
		return (ft_error());
	}
	free_list(stack_a);
	return (0);
}

// currenta = stack_a;
// 	printf("<A>\n");
// 	while (currenta)
// 	{
// 		printf("[%ld]\n", currenta->data);
// 		currenta = currenta->next;
// 	}
// 	printf("op-------->\n");
// //op>>>>>>>>>>>>>>>>>>>
// 	if (sorted_check(&stack_a))
// 	{
// 		len = len_stack(&stack_a);
// 		sort_stack(&stack_a, len);
// 	}
// 	currenta = stack_a;
// 	printf("<A>\n");
// 	while (currenta)
// 	{
// 		printf("[%ld]\n", currenta->data);
// 		currenta = currenta->next;
// 	}
// int	main(int argc, char **argv)
// {
// 	t_list	*stack_a;
// 	t_list	*stack_b;
// 	t_list	*currenta;
// 	t_list	*currentb;

// 	if (argc == 1)
// 		return (0);
// 	argv += 1;
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (check_arg(argv))
// 		return (ft_error());
// 	if(handle_arg(argv, &stack_a) == 1)
// 	{
// 		if (stack_a)
// 			free_list(stack_a);
// 		return (ft_error());
// 	}
// 	currenta = stack_a;
// 	currentb = stack_b;
// 	printf("<A>\t<B>\n");
// 	while (currenta || currentb)
// 	{
// 		if (currenta)
// 		{
// 			printf("[%ld]\t", currenta->data);
// 			currenta = currenta->next;
// 		}
// 		if (currentb)
// 		{
// 			printf("[%ld]", currentb->data);
// 			currentb = currentb->next;
// 		}
// 		printf("\n");
// 	}
// 	printf("op-------->\n");
// //op>>>>>>>>>>>>>>>>>>>

// 	sort_stack(&stack_a, &stack_b);
// 	currenta = stack_a;
// 	currentb = stack_b;
// 	printf("<A>\t<B>\n");
// 	while (currenta || currentb)
// 	{
// 		if (currenta)
// 		{
// 			printf("[%ld]\t", currenta->data);
// 			currenta = currenta->next;
// 		}
// 		if (currentb)
// 		{
// 			printf("[%ld]", currentb->data);
// 			currentb = currentb->next;
// 		}
// 		printf("\n");
// 	}
// 	free_list(stack_a);
// 	// free_list(stack_b);
// 	return 0;
// }