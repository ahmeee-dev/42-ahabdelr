/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:25:54 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/02/12 15:59:44 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
//bdau = b down, a up, buad è il contrario direzionale

void	total_cost(t_obj *obj)
{
	int	move_sum;

	if (obj->direction == 1 || obj->direction == 2)
		move_sum == obj->move_a * (obj->move_a >= obj->move_b) + obj->move_b * (obj->move_b > obj->move_a);
	else
		move_sum = obj->move_a + obj->move_b;
	obj->cost = move_sum;
}

void	choice(t_obj *obj, t_motion prev, t_motion next)
{
	int	prev_sum;
	int	next_sum;

	if (prev.direction == 1 || prev.direction == 2)
		prev_sum = prev.move_a * (prev.move_a >= prev.move_b) + prev.move_b * (prev.move_b > prev.move_a);
	else
		prev_sum = (prev.move_a + prev.move_b) * (prev.direction != -1) + INT_MAX * (prev.direction == -1);
	if (next.direction == 1 || next.direction == 2)
		next_sum = next.move_a * (next.move_a >= next.move_b) + next.move_b * (next.move_b > next.move_a);
	else
		next_sum = (next.move_a + next.move_b) * (next.direction != -1) + INT_MAX * (next.direction == -1);
	if (next_sum <= prev_sum)
	{
		obj->move_a = next.move_a;
		obj->move_b = next.move_b;
		obj->direction = next.direction;
	}
	else if (prev_sum < next_sum)
	{
		obj->move_a = prev.move_a;
		obj->move_b = prev.move_b;
		obj->direction = prev.direction;	
	}
}

int	save_move(t_motion *motion, int type)
{
	if (type == 1)
	{
		motion->move_a = motion->a_up;
		motion->move_b = motion->b_up;
		motion->direction = 1;
	}
	else if (type == 2)
	{
		motion->move_a = motion->a_down;
		motion->move_b = motion->b_down;
		motion->direction = 2;
	}
	else if (type == 3)
	{
		motion->move_a = motion->b_down;
		motion->move_b = motion->a_up;
		motion->direction = 3;
	}
	else if (type == 4)
	{
		motion->move_a = motion->a_down;
		motion->move_b = motion->b_down;
		motion->direction = 4;
	}
	return (0);
}

int	biggest(t_motion *motion)
{
	int	uppest;
	int	downest;
	int	mixed_buad;
	int	mixed_bdau;
	

	uppest = motion->b_up * (motion->b_up >= motion->a_up) + motion->a_up * (motion->a_up > motion->b_up);
	downest = motion->b_down * (motion->b_down >= motion->a_down) + motion->a_down * (motion->a_down > motion->b_down);
	mixed_bdau = motion->b_down + motion->a_up;
	mixed_buad = motion->b_up + motion->a_down;
	if (uppest < downest && uppest < mixed_bdau && uppest < mixed_buad)
		return (save_move(motion, 1));
	else if (downest < uppest && downest < mixed_bdau && downest < mixed_buad)
		return (save_move(motion, 2));
	else if (mixed_bdau < downest && mixed_bdau < uppest && mixed_bdau < mixed_buad)
		return (save_move(motion, 3));
	else if (mixed_buad < downest && mixed_buad < uppest && mixed_buad < mixed_bdau)
		return (save_move(motion, 4));
	return (0);
}


//da controllare il caso in cui mi trovi all'inizio o alla fine per la rotazione di a
t_motion	cost_prev(t_obj *obj, t_container *container)
{
	t_motion	motion;
	
	if (obj->b_index_prev >= 0)
	{
		motion.b_up = obj->b_index_prev;
		motion.b_down = container->index2 - obj->b_index_prev;
		motion.a_up = obj->index;
		motion.a_down = container->index1 - obj->index;
		biggest(&motion);
	}
	else 
		motion.direction = -1;
	return (motion);
}

t_motion	cost_next(t_obj *obj, t_container *container)
{
	t_motion	motion;

	if (obj->b_index_next >= 0)
	{
		motion.b_up = container->index2 - obj->b_index_next + 1;
		motion.b_down = container->index2 - obj->b_index_next - 1;
		motion.a_up = obj->index;
		motion.a_down = container->index1 - obj->index;
		biggest(&motion);
	}
	else
		motion.direction = -1;
	return (motion);
}

//ho assegnato i valori alla struttura x_motion, quella più grande darà i propri valori 'move a', 'move b' e 'direction' ad obj, non mi
// interessa se è prev o next perché in ogni caso eseguirà fino al push la stessa rotazione
void	costs(t_obj *obj, t_container *container)
{
	t_motion	prev_motion;
	t_motion	next_motion;

	prev_motion = cost_prev(obj, container);
	next_motion = cost_next(obj, container);
	choice(obj, prev_motion, next_motion);
	total_cost(obj);
}
