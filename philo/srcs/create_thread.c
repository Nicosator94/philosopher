/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/26 14:48:44 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_philo(t_data data, t_philo *philo, t_mutex *mutex)
{
	int	i;

	i = 0;
	while (i != data.nb_philo)
	{
		philo[i].data = copy_data(data);
		philo[i].number = i + 1;
		philo[i].actu_time = 0;
		philo[i].count = 0;
		philo[i].mutex = mutex;
		pthread_mutex_init(&philo[i].fork.fork, NULL);
		pthread_mutex_init(&philo[i].last_eat, NULL);
		philo[i].t_last_eat = 0;
		i ++;
	}
}

int	create_thread(t_data data, t_philo *philo, t_mutex *mutex)
{
	int	i;

	i = 0;
	set_philo(data, philo, mutex);
	while (i != data.nb_philo)
	{
		if (i + 1 == data.nb_philo)
			philo[i].next_fork = &philo[0].fork;
		else
			philo[i].next_fork = &philo[i + 1].fork;
		i ++;
	}
	i = 0;
	while (i != data.nb_philo)
	{
		if (pthread_create(&philo[i].thread_philo, NULL, fn_philo, &philo[i]) != 0)
			return (thread_create_failed());
		i ++;
	}
	return (0);
}
