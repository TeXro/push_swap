/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:27:14 by zzin              #+#    #+#             */
/*   Updated: 2025/02/13 14:04:05 by zzin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include "fcntl.h"

typedef struct t_list
{
	int				data;
	struct t_list	*next;
}	t_list;
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		*ft_int_split(char const *s);
char	*ft_memcpy(char *dst, char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_error(void);
int		rp_string(char *arg);
int		is_num(char **arg);
int		check_arg(char **arg);
void	sa(t_list **stacka);
void	sb(t_list **stackb);


#endif
