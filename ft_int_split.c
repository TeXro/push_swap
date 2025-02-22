/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:27:21 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 07:25:22 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	count_num(const char *s)
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

size_t	intlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	return (len);
}

long	res(const char *str)
{
	long	results;

	results = 0;
	while (*str >= '0' && *str <= '9')
	{
		results = results * 10 + (*str - '0');
		str++;
	}
	return (results);
}

long	charint(const char *s, size_t len)
{
	size_t	i;
	int		cs;
	int		pn;

	pn = 0;
	cs = 1;
	i = 0;
	while (s[i] == ' ' || ((s[i] >= 9 && s[i] <= 13) && (i < len)))
		i++;
	while (s[i] == '+' || (s[i] == '-' && (i < len)))
	{
		pn++;
		if (pn > 1)
			return (0);
		if (s[i] == '-')
			cs = -1;
		i++;
	}
	return (res(s + i) * cs);
}

long	*ft_int_split(char const *s)
{
	long	*result;
	int		i;
	long	numbers;

	if (!s)
		return (NULL);
	i = 0;
	numbers = count_num(s);
	result = malloc(sizeof(long) * (numbers + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < numbers)
	{
		while (*s == ' ')
			s++;
		if (is_max(s) == 1)
			return (free (result), NULL);
		result[i] = charint(s, intlen(s));
		s += intlen(s);
		i++;
	}
	result[i] = 9999999999;
	return (result);
}
