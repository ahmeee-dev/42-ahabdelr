/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/05 10:51:41 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_eat
{
	int		prev;
	int		next;
	int		actual;
	int		phi_num;
}			t_eat;

typedef struct s_data
{
	sem_t	*print;
	sem_t	*check;
	sem_t	*order;
	int		alive;
	int		objective;
	int		to_eat;
	int		to_die;
	int		ph_number;
	int		to_sleep;
	int		times_eat;
}			t_data;

int			mytoi(char *str);
void		process_creation(t_data *data);
int			philo_check(t_data *data);
void		print_sleep(int i, t_data *data);
void		print_death(int i, t_data *data);
void		print_eat(int i, t_data *data, int *last_meal);
void		print_fork(int i, t_data *data);
int			check_deat(int i, t_data *data, int *last_meal);
void		routine(int i, t_data *data);
void		print_think(int i, t_data *data);
#endif
