/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by niromano          #+#    #+#             */
/*   Updated: 2023/09/22 13:23:46 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_printf(t_philo *philo, int trigger)
{
	pthread_mutex_lock(&philo->mutex->death);
	if (philo->mutex->d_trig != 1)
	{
		pthread_mutex_unlock(&philo->mutex->death);
		pthread_mutex_lock(&philo->mutex->printf);
		if (trigger == 1)
			printf("%lld %d has taken a fork\n", get_time()
				- philo->data.time_start, philo->number);
		else if (trigger == 2)
			printf("%lld %d is eating\n", get_time()
				- philo->data.time_start, philo->number);
		else if (trigger == 3)
			printf("%lld %d is sleeping\n", get_time()
				- philo->data.time_start, philo->number);
		else if (trigger == 4)
			printf("%lld %d is thinking\n", get_time()
				- philo->data.time_start, philo->number);
		else if (trigger == 5)
			printf("%lld %d died\n", get_time()
				- philo->data.time_start, philo->number);
		pthread_mutex_unlock(&philo->mutex->printf);
	}
	else
		pthread_mutex_unlock(&philo->mutex->death);
}
