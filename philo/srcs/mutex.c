/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by niromano          #+#    #+#             */
/*   Updated: 2023/09/25 11:56:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_printf(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->mutex->death);
	if (philo->mutex->d_trig != 1)
	{
		pthread_mutex_unlock(&philo->mutex->death);
		pthread_mutex_lock(&philo->mutex->printf);
		printf(s, get_time() - philo->data.time_start, philo->number);
		pthread_mutex_unlock(&philo->mutex->printf);
	}
	else
		pthread_mutex_unlock(&philo->mutex->death);
}
