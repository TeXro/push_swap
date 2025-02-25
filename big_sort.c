/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:44:14 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/25 06:35:41 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(int *start, int *end, int size)
{
	if (*start < *end)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}

int	find_max(t_list **stack_b)
{
	t_list	*temp;
	int		max;
	int		i;
	int		max_index;

	temp = *stack_b;
	max = temp->data;
	i = 0;
	max_index = 0;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_index);
}

void	push_to_b(t_list **stk_a, t_list **stk_b, int *arr, int arr_end)
{
	int	arr_start;
	int	size;

	size = len_stack(stk_a);
	arr_start = 0;
	while (*stk_a)
	{
		if ((*stk_a)->data <= arr[arr_start])
		{
			printf("if>%ld @ %d?%d\n", (*stk_a)->data, arr[arr_start] , arr[arr_end]);
			pb(stk_a, stk_b);
			if ((*stk_b)->next)
				rb(stk_b);
			update_index(&arr_start, &arr_end, size);
		}
		else if ((*stk_a)->data <= arr[arr_end])
		{
			printf("ei>%ld @ %d?%d\n", (*stk_a)->data, arr[arr_start] , arr[arr_end]);
			pb(stk_a, stk_b);
			update_index(&arr_start, &arr_end, size);
			if ((*stk_b)->next && (*stk_b)->data < (*stk_b)->next->data)
				sb(stk_b);
		}
		else{
			printf("el%ld @ %d?%d\n", (*stk_a)->data, arr[arr_start] , arr[arr_end]);
			ra(stk_a);
		}
	}
}

void	push_back_a(t_list **stk_a, t_list **stk_b)
{
	int	max;
	int	len;

	while (*stk_b != NULL)
	{
		max = find_max(stk_b);
		printf("(max=%d)\n", max);
		len = len_stack(stk_b);
		printf("(len=%d)\n", len / 2);
		if (max == 0)
			pa(stk_a, stk_b);
		else if (max <= len / 2)
		{
			while (find_max(stk_b) != 0)
				rb(stk_b);
		}
		else
		{
			while (find_max(stk_b) != 0)
				rrb(stk_b);
		}
	}
}

void	big_sort(t_list **stk_a, t_list **stk_b, int size)
{
	int	arr_end;
	int	*arr;
	int i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	fill_arr(stk_a, arr);
	while (i < size)
	{
		printf("arr[%d]\n", arr[i]);
		i++;
	}
	sort_in_table(arr, size);
	printf("------->\n");
	i = 0;
	while (i < size)
	{
		printf("arr[%d]\n", arr[i]);
		i++;
	}
	printf("------->\n");
	if (size <= 100)
		arr_end = size / 6;
	else
		arr_end = size / 14;
	printf("(arr_end=%d)\n", arr_end);
	push_to_b(stk_a, stk_b, arr, arr_end);
	printf("------->\n");
	free(arr);
	push_back_a(stk_a, stk_b);
	printf("------->\n");

}
