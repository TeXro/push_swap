/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:18:36 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 07:18:58 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max_n(char const *s)
{
	size_t	len;
	int		last_dg;

	while (*s == '0')
	{
		s++;
	}
	len = intlen(s);
	if (len > 10)
		return (1);
	if (len == 10)
	{
		last_dg = s[len - 1] - '0';
		if (last_dg > 8)
			return (1);
	}
	return (0);
}

int	is_max(char const *s)
{
	size_t	len;
	int		last_dg;

	if (*s == '-' || *s == '+')
		return (is_max_n(++s));
	while (*s == '0')
		s++;
	len = intlen(s);
	if (len > 10)
		return (1);
	if (len == 10)
	{
		last_dg = s[len - 1] - '0';
		if (last_dg > 7)
			return (1);
	}
	return (0);
}
