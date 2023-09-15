/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by niromano          #+#    #+#             */
/*   Updated: 2023/09/15 11:55:05 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	mutex_printf(t_philo *philo, int trigger)
// {
// 	pthread_mutex_lock(philo->data.m_printf);
// 	if (trigger == 1)
// 		printf("%ld %d has taken a fork\n", get_time() - philo->data.time_start, philo->number);
// 	else if (trigger == 2)
// 		printf("%ld %d is eating\n", get_time() - philo->data.time_start, philo->number);
// 	else if (trigger == 3)
// 		printf("%ld %d is sleeping\n", get_time() - philo->data.time_start, philo->number);
// 	else if (trigger == 4)
// 		printf("%ld %d is thinking\n", get_time() - philo->data.time_start, philo->number);
// 	pthread_mutex_unlock(philo->data.m_printf);
// }