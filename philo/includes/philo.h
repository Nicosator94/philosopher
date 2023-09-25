/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:11:16 by niromano          #+#    #+#             */
/*   Updated: 2023/09/25 12:20:02 by niromano         ###   ########.fr       */
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
	pthread_mutex_t	counter;
	int				d_trig;
	int				count;
}					t_mutex;

typedef struct s_data
{
	int			nb_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			nb_t_eat;
	long long	time_start;
}				t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	pthread_mutex_t	state;
	int				open;
}					t_fork;

typedef struct s_philo
{
	int			number;
	pthread_t	thread_philo;
	t_fork		fork;
	t_fork		*next_fork;
	long long	actu_time;
	t_data		data;
	long long	before_die;
	long long	old_die;
	t_mutex		*mutex;
	int			count;
}				t_philo;

int			parsing(int argc, char *argv[]);
long		ft_atoi(const char *nptr);

t_data		init_data(int argc, char *argv[]);
long long	get_time(void);

int			check_max(t_data data);
int			check_nb_philo(t_data data);

int			sadly_alone_guy(t_data data, t_philo *philo, t_mutex *mutex);

int			create_thread(t_data data, t_philo *philo, t_mutex *mutex);
t_data		copy_data(t_data data);
void		*fn_philo(void *arg);

int			death(t_philo *philo);
void		mutex_printf(t_philo *philo, char *s);

int			mutex_init_failed();
int			thread_create_failed();

#endif