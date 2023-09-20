/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:37:13 by niromano          #+#    #+#             */
/*   Updated: 2023/09/20 12:08:15 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->next_fork);
	philo->actu_time = get_time() - philo->data.time_start;
	if (death(philo) == 1)
	{
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	mutex_printf(philo, 1);
	mutex_printf(philo, 1);
	mutex_printf(philo, 2);
	philo->old_die = philo->old_die + philo->before_die;
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat)
	{
		if (death(philo) == 1)
		{
			pthread_mutex_unlock(philo->next_fork);
			pthread_mutex_unlock(&philo->fork);
			return (1);
		}
	}
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(&philo->fork);
	if (philo->count != -1)
		philo->count += 1;
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, 3);
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_sleep)
	{
		if (death(philo) == 1)
			return (1);
	}
	mutex_printf(philo, 4);
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat - philo->data.t_sleep)
	{
		if (death(philo) == 1)
			return (1);
	}
	return (0);
}

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	mutex_printf(philo, 4);
	if (philo->number % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
