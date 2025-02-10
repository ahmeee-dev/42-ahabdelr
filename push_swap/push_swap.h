/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:57:10 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/10 10:04:02 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

//direction 1 is up, 2 is down
typedef struct	s_container
{
	int	*array1;
	int	*array2;
	int	*ordered;
	int	size;
	int	index1;
	int	index2;
	int	count;
	int	direction;
}		t_container;

//algorithm
void	algo(t_container *container);

//array
int	*array_creation(char **numbers, int size);

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