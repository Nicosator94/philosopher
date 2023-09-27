/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:09:08 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 11:39:24 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i != philo->data.nb_philo)
	{
		pthread_mutex_destroy(&philo[i].fork.fork);
		pthread_mutex_destroy(&philo[i].last_eat);
		i ++;
	}
	free(philo);
}

void	destroy_mutex(t_mutex *mutex)
{
	pthread_mutex_destroy(&mutex->counter);
	pthread_mutex_destroy(&mutex->death);
	pthread_mutex_destroy(&mutex->end);
	pthread_mutex_destroy(&mutex->printf);
	free(mutex);
}
