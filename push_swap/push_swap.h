/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:57:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/15 19:58:18 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_obj
{
	int	sort;
	int	index;
	int	value;
	int	pos;
	int	height;
}		t_obj;

//direction 1 is up, 2 is down
typedef struct	s_container
{
	t_obj	*array1;
	t_obj	*array2;
	int	*ordered;
	int	size;
	int	index1;
	int	index2;
	int	count;
}		t_container;

//algorithm
void	recursive_sort(t_container *container, int ab_min, int max);
int	*oder_array(t_container *container);
void	move_to_top(t_container *container, int min, int max);
void	base_case(t_container *container, int min, int max);
void	sort_three_top_a(t_container *container, int min, int max);
void	sort_three_bottom_a(t_container *container, int min, int max);
void	sort_three_bottom_b(t_container *container, int min, int max);
void	sort_three_top_b(t_container *container, int min, int max);


void	move_from_bottom_b(t_container *container, int size);
void	move_from_top_b(t_container *container, int size);
void	move_from_bottom_a(t_container *container, int size);
void	move_from_top_a(t_container *container, int size);


//array
t_obj	*array_creation(char **numbers, int size);

//swap
void	sa(t_container *container);
void	sb(t_container *container);
void	ss(t_container *container);

//push & push utils
void	pa(t_container *container);
void	pb(t_container *container);
void	get_up1(t_container *container);
void	get_up2(t_container *container);
void	get_low1(t_container *container);
void	get_low2(t_container *container);

//rotate
void	ra(t_container *container);
void	rb(t_container *container);
void	rr(t_container *container);

//reverse rotate
void	rev_rr(t_container *container);
void	rev_rb(t_container *container);
void	rev_ra(t_container *container);



#endif
