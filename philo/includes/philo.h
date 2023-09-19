/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:11:16 by niromano          #+#    #+#             */
/*   Updated: 2023/09/19 11:23:18 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_mutex
{
	pthread_mutex_t	printf;
	pthread_mutex_t	death;
	int				d_trig;
}					t_mutex;

typedef struct s_data
{
	long	nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_t_eat;
	long	time_start;
}					t_data;

typedef struct s_philo
{
	int				number;
	pthread_t		thread_philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	long			actu_time;
	t_data			data;
	long			before_die;
	long			old_die;
	t_mutex			*mutex;
}					t_philo;

int		parsing(int argc, char *argv[]);
long	ft_atoi(const char *nptr);

t_data	init_data(int argc, char *argv[]);
long	get_time(void);

int		check_max(t_data data);
int		check_nb_philo(t_data data);

int		create_thread(t_data data, t_philo *philo, t_mutex *mutex);

void	mutex_printf(t_philo *philo, int trigger);

#endif