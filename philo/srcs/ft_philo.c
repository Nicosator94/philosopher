/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:06:41 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 11:24:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	thread(t_data data, t_philo *philo, t_mutex *mutex)
{
	if (philo == NULL)
	{
		printf("Error\nMalloc Failed\n");
		destroy_mutex(mutex);
		return (1);
	}
	if (data.nb_philo == 1)
	{
		if (sadly_alone_guy(data, philo, mutex) == 1)
		{
			destroy_philo(philo);
			destroy_mutex(mutex);
			return (1);
		}
	}
	else
	{
		if (create_thread(data, philo, mutex) == 1)
		{
			destroy_philo(philo);
			destroy_mutex(mutex);
			return (1);
		}
	}
	return (0);
}

int	ft_philo(t_data data, t_mutex *mutex)
{
	int		i;
	t_philo	*philo;

	i = 0;
	if (check_max(data) == 1 || check_nb_philo(data) == 1)
	{
		destroy_mutex(mutex);
		return (1);
	}
	data.time_start = get_time();
	philo = malloc(sizeof(t_philo) * data.nb_philo);
	if (thread(data, philo, mutex) == 1)
		return (1);
	if (data.nb_philo > 1)
		death(philo);
	while (i != data.nb_philo)
	{
		pthread_join(philo[i].thread_philo, NULL);
		i ++;
	}
	destroy_philo(philo);
	return (0);
}
