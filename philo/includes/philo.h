/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:11:16 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 10:54:03 by niromano         ###   ########.fr       */
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

typedef struct s_philo
{
	int		num;
}				t_philo;

typedef struct s_data
{
	long	nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	long	nb_t_eat;
	t_philo	*philo;
}				t_data;

int		parsing(int argc, char *argv[]);
long	ft_atoi(const char *nptr);
int		check_max(t_data data);
int		check_nb_philo(t_data data);

int		create_thread(t_data data);

#endif