/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:20:48 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 08:16:01 by niromano         ###   ########.fr       */
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

int	cycle_for_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->next_fork->fork);
	pthread_mutex_lock(&philo->fork.fork);
	mutex_printf(philo, "%lld %d has taken a fork\n");
	mutex_printf(philo, "%lld %d has taken a fork\n");
	mutex_printf(philo, "%lld %d is eating\n");
	philo->actu_time = get_time() - philo->data.time_start;
	pthread_mutex_lock(&philo->last_eat);
	philo->t_last_eat = get_time() - philo->data.time_start;
	pthread_mutex_unlock(&philo->last_eat);
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat)
	{
		if (check_death(philo) == 1)
		{
			pthread_mutex_unlock(&philo->fork.fork);
			pthread_mutex_unlock(&philo->next_fork->fork);
			return (1);
		}
		usleep(50);
	}
	pthread_mutex_unlock(&philo->fork.fork);
	pthread_mutex_unlock(&philo->next_fork->fork);
	philo->count += 1;
	if (check_end(philo) == 1)
		return (1);
	mutex_printf(philo, "%lld %d is sleeping\n");
	philo->actu_time = get_time() - philo->data.time_start;
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_sleep)
	{
		if (check_death(philo) == 1)
			return (1);
		usleep(50);
	}
	mutex_printf(philo, "%lld %d is thinking\n");
	philo->actu_time = get_time() - philo->data.time_start;
	return (0);
}

int	cycle_for_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork.fork);
	pthread_mutex_lock(&philo->next_fork->fork);
	mutex_printf(philo, "%lld %d has taken a fork\n");
	mutex_printf(philo, "%lld %d has taken a fork\n");
	mutex_printf(philo, "%lld %d is eating\n");
	philo->actu_time = get_time() - philo->data.time_start;
	pthread_mutex_lock(&philo->last_eat);
	philo->t_last_eat = get_time() - philo->data.time_start;
	pthread_mutex_unlock(&philo->last_eat);
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat)
	{
		if (check_death(philo) == 1)
		{
			pthread_mutex_unlock(&philo->next_fork->fork);
			pthread_mutex_unlock(&philo->fork.fork);
			return (1);
		}
		usleep(50);
	}
	pthread_mutex_unlock(&philo->next_fork->fork);
	pthread_mutex_unlock(&philo->fork.fork);
	philo->count += 1;
	if (check_end(philo) == 1)
		return (1);
	mutex_printf(philo, "%lld %d is sleeping\n");
	philo->actu_time = get_time() - philo->data.time_start;
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_sleep)
	{
		if (check_death(philo) == 1)
			return (1);
		usleep(50);
	}
	mutex_printf(philo, "%lld %d is thinking\n");
	philo->actu_time = get_time() - philo->data.time_start;
	return (0);
}
