/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:21:16 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 06:33:55 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	fill_arr(t_list **stack_a, int *arr)
{
	t_list	*temp;
	int		i;

	temp = *stack_a;
	i = 0;
	while (temp)
	{
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
