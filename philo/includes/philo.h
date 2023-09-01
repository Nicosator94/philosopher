/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:11:16 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 12:53:02 by niromano         ###   ########.fr       */
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

typedef struct s_time
{
	long		start;
	long		now;
	int			stop;
	pthread_t	thread_time;
}				t_time;

typedef struct s_data
{
	long	nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_t_eat;
	t_time	time;
}				t_data;

typedef struct s_philo
{
	int			number;
	pthread_t	thread_philo;
	int			number_eat;
	t_data		*data;
}				t_philo;

int		parsing(int argc, char *argv[]);
long	ft_atoi(const char *nptr);

t_data	init_data(int argc, char *argv[]);
void	*actualize_time(void *arg);

int		check_max(t_data data);
int		check_nb_philo(t_data data);

int		create_thread(t_data data, t_philo *philo);

#endif