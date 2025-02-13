/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:58:15 by zzin              #+#    #+#             */
/*   Updated: 2025/02/13 21:53:38 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rp_string(char *arg)
{
	int c = 0;
	int b = 0;

	while (arg[c])
	{
		printf("(c%d)\n", c);
		b = c + 1;
		while (arg[b])
		{
			if (arg[c] != arg[b])
			{
				printf("b1> %d c> %d\n", b, c);
				while (arg[b] != ' ' && arg[b])
				{
					b++;
					printf("b2> %d c> %d\n", b, c);
				}
				while (arg[b] == ' ')
					b++;
				printf("b3> %d c> %d\n", b, c);
				continue;
			}
			if (arg[c] == arg[b] && (arg[c] && arg[b]))
			{
				printf("Mb1> %d c> %d\n", b, c);
				c++;
				b++;
				if (((!arg[b] || arg[b] == ' ')  && (!arg[c] || arg[c] == ' ')))
					return 1;
				continue;
			}
		}
		c++;
	}
	return 0;
}

int is_empty(char **argv)
{
	int i;
	int c;

	i = 0;
	while (argv[i])
	{
		c = 0;
		if (argv[i][c] == '\0')
			return 1;
		while (argv[i][c])
		{
			if (argv[i][c] != ' ' && argv[i][c] != '\t')
				break;
			c++;
			if (argv[i][c] == '\0')
				return 1;
		}
		i++;
	}
	return 0;
	
}

int is_num(char **arg)
{
	int	i;
	int	c;

	i = 0;
	while (arg[i])
	{
		c = 0;
		while (arg[i][c])
		{
			if (arg[i][c + 1] == '+' || arg[i][c + 1] == '-') 
				return 1;
			if ((arg[i][c] != '+') && (arg[i][c] != '-')){
				if((arg[i][c] < '0' || arg[i][c] > '9') && (arg[i][c] != ' '))
					return 1;
			}
			c++;
		}
		i++;
	}
	return 0;
}
// int is_double
		
int check_arg(char **arg)
{
	if (is_empty(arg) == 1)
		return 1;
	if (is_num(arg) == 1)
		return 1;
	return 0;
}