/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:31 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 10:35:56 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	one_by_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eat);
	if (get_time() - philo->data.time_start
		- philo->t_last_eat > philo->data.t_die)
	{
		pthread_mutex_lock(&philo->mutex->end);
		philo->mutex->trigger_end = 1;
		pthread_mutex_unlock(&philo->mutex->end);
		pthread_mutex_lock(&philo->mutex->printf);
		printf("%lld %d died\n", get_time()
			- philo->data.time_start, philo->number);
		pthread_mutex_unlock(&philo->mutex->printf);
		pthread_mutex_unlock(&philo->last_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_eat);
	return (0);
}

void	death(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->mutex->end);
	while (i != philo[0].data.nb_philo && philo->mutex->trigger_end != 1)
	{
		pthread_mutex_unlock(&philo->mutex->end);
		if (one_by_one(&philo[i]) == 1)
			return ;
		i ++;
		if (i == philo->data.nb_philo)
			i = 0;
		pthread_mutex_lock(&philo->mutex->end);
	}
	pthread_mutex_unlock(&philo->mutex->end);
}
