/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:57:31 by niromano          #+#    #+#             */
/*   Updated: 2023/09/20 13:41:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	count_death(t_philo *philo)
{
	if (philo->count == philo->data.nb_t_eat)
	{
		pthread_mutex_lock(&philo->mutex->counter);
		philo->mutex->count += 1;
		pthread_mutex_unlock(&philo->mutex->counter);
		philo->count += 1;
	}
	pthread_mutex_lock(&philo->mutex->counter);
	if (philo->mutex->count == philo->data.nb_philo)
	{
		pthread_mutex_unlock(&philo->mutex->counter);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->counter);
	return (0);
}

int	angry_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->death);
	if (philo->mutex->d_trig == 1)
	{
		pthread_mutex_unlock(&philo->mutex->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->death);
	philo->before_die = (get_time() - philo->data.time_start) - philo->old_die;
	if (philo->before_die > philo->data.t_die)
	{
		mutex_printf(philo, 5);
		pthread_mutex_lock(&philo->mutex->death);
		philo->mutex->d_trig = 1;
		pthread_mutex_unlock(&philo->mutex->death);
		return (1);
	}
	return (0);
}

int	death(t_philo *philo)
{
	if (count_death(philo) == 1)
		return (1);
	if (angry_death(philo) == 1)
		return (1);
	return (0);
}
