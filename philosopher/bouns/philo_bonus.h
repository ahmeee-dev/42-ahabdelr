/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <ahabdelr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:50 by ahabdelr          #+#    #+#             */
/*   Updated: 2025/03/03 16:46:32 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>


typedef struct s_eat
{
	int				prev;
	int				next;
	int				actual;
	int				phi_num;
}					t_eat;

typedef struct s_data
{
	sem_t	check;
	int				alive;
	int				objective;
	int				to_eat;
	int				to_die;
	int				ph_number;
	int				to_sleep;
	int				times_eat;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				number;
	int				ate;
	sem_t	sem;
	t_data			*data;
}					t_philo;

int					mytoi(char *str);

#endif
