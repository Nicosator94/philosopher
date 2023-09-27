/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:55:58 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 10:56:14 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->end);
	if (philo->mutex->trigger_end == 1)
	{
		pthread_mutex_unlock(&philo->mutex->end);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->end);
	return (0);
}

int	check_end(t_philo *philo)
{
	if (check_death(philo) == 1)
		return (1);
	if (philo->count == philo->data.nb_t_eat)
	{
		pthread_mutex_lock(&philo->mutex->counter);
		philo->mutex->count += 1;
		if (philo->mutex->count == philo->data.nb_philo)
		{
			pthread_mutex_unlock(&philo->mutex->counter);
			pthread_mutex_lock(&philo->mutex->end);
			philo->mutex->trigger_end = 1;
			pthread_mutex_unlock(&philo->mutex->end);
			return (1);
		}
		pthread_mutex_unlock(&philo->mutex->counter);
		philo->count += 1;
	}
	return (0);
}
