/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:01:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 11:02:08 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_mutex *mutex)
{
	if (mutex == NULL)
	{
		printf("Error\n");
		printf("Malloc Failed\n");
		return (1);
	}
	if (pthread_mutex_init(&mutex->printf, NULL) != 0)
		return (mutex_init_failed());
	if (pthread_mutex_init(&mutex->death, NULL) != 0)
		return (mutex_init_failed());
	if (pthread_mutex_init(&mutex->end, NULL) != 0)
		return (mutex_init_failed());
	if (pthread_mutex_init(&mutex->counter, NULL) != 0)
		return (mutex_init_failed());
	mutex->trigger_end = 0;
	mutex->count = 0;
	return (0);
}
