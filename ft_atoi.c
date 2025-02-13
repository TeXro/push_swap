/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:02:46 by zzin              #+#    #+#             */
/*   Updated: 2025/02/13 14:27:04 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	res(const char *str)
{
	int	results;

	results = 0;
	while (*str >= '0' && *str <= '9')
	{
		results = results * 10 + (*str - '0');
		str++;
	}
	return (results);
}

int	ft_atoi(const char *str)
{
	int	cs;
	int	pn;

	pn = 0;
	cs = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		pn++;
		if (pn > 1)
			return (0);
		if (*str == '-')
			cs = -1;
		str++;
	}
	return (res(str) * cs);
}
