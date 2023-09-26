/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_for_odd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:21:04 by niromano          #+#    #+#             */
/*   Updated: 2023/09/26 07:39:44 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork.fork);
	pthread_mutex_lock(&philo->fork.state);
	philo->fork.open = 1;
	pthread_mutex_unlock(&philo->fork.state);
	mutex_printf(philo, "%lld %d has taken a fork\n");
	if (death(philo) == 1)
	{
		pthread_mutex_unlock(&philo->fork.fork);
		return (1);
	}
	pthread_mutex_lock(&philo->next_fork->fork);
	pthread_mutex_lock(&philo->next_fork->state);
	philo->next_fork->open = 1;
	pthread_mutex_unlock(&philo->next_fork->state);
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, "%lld %d has taken a fork\n");
	return (0);
}

int	eating_odd(t_philo *philo)
{
	mutex_printf(philo, "%lld %d is eating\n");
	philo->old_die = get_time() - philo->data.time_start;
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat)
	{
		usleep(10);
		if (death(philo) == 1)
		{
			pthread_mutex_unlock(&philo->next_fork->fork);
			pthread_mutex_unlock(&philo->fork.fork);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->next_fork->fork);
	pthread_mutex_unlock(&philo->fork.fork);
	pthread_mutex_lock(&philo->fork.state);
	philo->fork.open = 0;
	pthread_mutex_unlock(&philo->fork.state);
	pthread_mutex_lock(&philo->next_fork->state);
	philo->next_fork->open = 0;
	pthread_mutex_unlock(&philo->next_fork->state);
	philo->count += 1;
	return (0);
}

int	sleeping_odd(t_philo *philo)
{
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, "%lld %d is sleeping\n");
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_sleep)
	{
		usleep(10);
		if (death(philo) == 1)
			return (1);
	}
	return (0);
}

int	thinking_odd(t_philo *philo)
{
	mutex_printf(philo, "%lld %d is thinking\n");
	pthread_mutex_lock(&philo->fork.state);
	pthread_mutex_lock(&philo->next_fork->state);
	while (philo->fork.open == 1 || philo->next_fork->open == 1)
	{
		usleep(10);
		pthread_mutex_unlock(&philo->next_fork->state);
		pthread_mutex_unlock(&philo->fork.state);
		if (death(philo) == 1)
			return (1);
		pthread_mutex_lock(&philo->fork.state);
		pthread_mutex_lock(&philo->next_fork->state);
	}
	pthread_mutex_unlock(&philo->next_fork->state);
	pthread_mutex_unlock(&philo->fork.state);
	return (0);
}

int	cycle_for_odd(t_philo *philo)
{
	if (take_fork_odd(philo) == 1)
		return (1);
	if (eating_odd(philo) == 1)
		return (1);
	if (sleeping_odd(philo) == 1)
		return (1);
	if (thinking_odd(philo) == 1)
		return (1);
	return (0);
}
