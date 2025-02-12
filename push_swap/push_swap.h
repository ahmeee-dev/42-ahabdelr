/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:57:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 15:49:07 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_move
{
	int	moves;
	int	direction;
}		t_move;

typedef struct	s_motion
{
	int	b_up;
	int	b_down;
	int	a_up;
	int	a_down;
	int	move_a;
	int	move_b;
	int	direction;
}		t_motion;

typedef struct	s_obj
{
	int	cost;
	int	move_a;
	int	move_b;
	int	direction;
	int	index;
	int	value;
	int	b_index_next;
	int	b_index_prev;
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
	t_move	move;
}		t_container;

//algorithm
void	algo(t_container *container);
void	set_of_3(t_container *container);

//moves count
void	moves_exec(t_container *container);
void	moves_check(t_container *container, int k, int m);
void	order(t_container *container);
void	move_number(t_container *container);
int	moves_number_next(t_container *container);
int	moves_number_prev(t_container *container);



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
