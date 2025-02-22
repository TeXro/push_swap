/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzin <zzin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:27:14 by zzin              #+#    #+#             */
/*   Updated: 2025/02/22 05:34:09 by zzin             ###   ########.fr       */
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
	long			data;
	struct t_list	*next;
}	t_list;
void	new_node(t_list **stack, long num);
void	free_list(t_list *head);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
long	*ft_int_split(char const *s);
char	*ft_memcpy(char *dst, char *src, size_t n);
int		ft_error(void);
int		is_num(char **arg);
int		check_arg(char **arg);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
long	*ft_long_join(long *nums1, long *nums2);
void	s_sort(t_list **stack_a, t_list **stack_b);

#endif
