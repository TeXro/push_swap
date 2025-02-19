/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:58:15 by zzin              #+#    #+#             */
/*   Updated: 2025/02/19 15:55:47 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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