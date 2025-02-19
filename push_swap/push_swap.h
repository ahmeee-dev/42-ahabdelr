/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:57:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/19 10:28:50 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

// direction 1 is up, 2 is down
typedef struct s_container
{
	int		*array1;
	int		*array2;
	int		index1;
	int		index2;
	int		count;
	char	**str;
	int		type;
}			t_container;

// base cases
int			base_case_a(t_container *s, int size);
int			base_case_b(t_container *s, int size);
void		get_middle(int *array, int size, int *pivot);
int			quick_sort_b(t_container *container, int size);

// algorithm
int			already_sorted(t_container *container, int size, int type);
void		fast_sort_a(t_container *container);
void		fast_sort_a(t_container *n);
int			quick_sort_a(t_container *container, int size);

// array
int			push_swap_atoi(t_container *cont, char *str, int *array);
void		repeat_check(t_container *cont, int *array, int size);
char		**ps_split(const char *s, char c);
int			*array_creation(t_container *cont, char **numbers, int size);

// swap
void		sa(t_container *container);
void		sb(t_container *container);
void		ss(t_container *container);

// push & push utils
void		pa(t_container *container);
void		pb(t_container *container);
void		get_up1(t_container *container);
void		get_up2(t_container *container);
void		get_low1(t_container *container);
void		get_low2(t_container *container);

// rotate
void		ra(t_container *container);
void		rb(t_container *container);
void		rr(t_container *container);

// reverse rotate
void		rev_rr(t_container *container);
void		rev_rb(t_container *container);
void		rev_ra(t_container *container);

#endif
