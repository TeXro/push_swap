/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:36:41 by zzin              #+#    #+#             */
/*   Updated: 2025/02/19 22:09:16 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



long *ft_longjoin(long *nums1, long *nums2)
{
	long *res;
	
	res = malloc(sizeof(int));
}

int main()
{
	long *arr = ft_int_split("91 92 93");
	// printf("%ld\n", arr[0]);
	// printf("%ld\n", arr[1]);
	// printf("%ld\n", arr[2]);
	int i = 0;
	while (arr[i] != 9999999999)
	{
		printf("%ld\n", arr[i]);
		i++;
	}
	
	free(arr);
}