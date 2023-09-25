/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:37:13 by niromano          #+#    #+#             */
/*   Updated: 2023/09/25 07:58:57 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork.fork);
	pthread_mutex_lock(&philo->fork.state);
	philo->fork.open = 1;
	pthread_mutex_unlock(&philo->fork.state);
	mutex_printf(philo, 1);
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
	mutex_printf(philo, 1);
	return (0);
}

int	eating(t_philo *philo)
{
	mutex_printf(philo, 2);
	philo->old_die = get_time() - philo->data.time_start;
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_eat)
	{
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

int	sleeping(t_philo *philo)
{
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, 3);
	while (get_time() - (philo->data.time_start
			+ philo->actu_time) < philo->data.t_sleep)
	{
		if (death(philo) == 1)
			return (1);
	}
	return (0);
}

int	thinking(t_philo *philo)
{
	mutex_printf(philo, 4);
	pthread_mutex_lock(&philo->fork.state);
	pthread_mutex_lock(&philo->next_fork->state);
	while (philo->fork.open == 1 || philo->next_fork->open == 1)
	{
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

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	mutex_printf(philo, 4);
	if (philo->number % 2 == 0)
		usleep(100);
	while (1)
	{
		usleep(100);
		philo->data.time_start += 0.1;
		if (take_fork(philo) == 1)
			return (NULL);
		if (eating(philo) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
		if (thinking(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
