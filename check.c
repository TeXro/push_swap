/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:58:15 by zzin              #+#    #+#             */
/*   Updated: 2025/02/11 22:29:21 by zzin             ###   ########.fr       */
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

int repeat(char **argv)
{
	int i = 0;
	int p = 0;
	int c = 0;
	int b = 0;

	while (argv[i])
	{
		p = i + 1;
		b = 0;
		c = 0;
		//			i      p    
		//         [0]    [1]          [2] [3] [4] [5] [6]
		// 			12     "33  5 12 6 "
		// 		   --b------------c------------
		// 		    012    012 0 0 0
		while (argv[p])
		{
			if (argv[i][b] != argv[p][c])
			{
				if (ft_strchr(argv[i] + b, ' '))
				{
					while ((argv[i][b]) != ' ')
						b++;
					while ((argv[i][b]) == ' ')
						b++;
					continue;
				}
				if (ft_strchr(argv[p] + c, ' '))
				{
					while ((argv[p][c]) != ' ')
						c++;
					while ((argv[p][c]) == ' ')
						c++;
					b = 0;
					continue;
				}
				p++;
				c = 0;
				b = 0;	
				continue;
			}
			if (argv[i][b] == argv[p][c] && (argv[i][b] && argv[p][c]))
			{
				c++;
				b++;
				if (((!argv[i][b] || argv[i][b] == ' ')  && (!argv[p][c] || argv[p][c] == ' ')))
					return 1;
				continue;
			}
		}
		i++;
	}
	return 0;
}
int is_valid(char **arg)
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

int check_arg(char **arg)
{	
	if (is_valid(arg) == 1)
		return 1;
	return 0;
}