/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by niromano          #+#    #+#             */
/*   Updated: 2023/09/26 15:32:36 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_printf(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->mutex->printf);
	pthread_mutex_lock(&philo->mutex->end);
	if (philo->mutex->trigger_end != 1)
		printf(s, get_time() - philo->data.time_start, philo->number);
	pthread_mutex_unlock(&philo->mutex->end);
	pthread_mutex_unlock(&philo->mutex->printf);
}
