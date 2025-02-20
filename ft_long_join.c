/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:55:26 by zzin              #+#    #+#             */
/*   Updated: 2025/02/20 06:30:49 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t long_nums(long *num)
{
	size_t len;

	len = 0;
	if (num == NULL)
		return len;
	while (num[len] != 9999999999)
		len++;
	return len;
}

long *ft_long_join(long *nums1, long *nums2)
{
	long	*res;
	size_t	l1;
	size_t	l2;
	int		i;

	l1 = long_nums(nums1);
	l2 = long_nums(nums2);
	i = 0;
	res = malloc(sizeof(long) * (l1 + l2 + 1));
	while (l1)
		res[i++] = nums1[--l1];
	free(nums1);
	while (l2)
		res[i++] = nums2[--l2];
	res[i] = 9999999999;
	return (res);
}
