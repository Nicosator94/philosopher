/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/09/25 08:51:34 by niromano         ###   ########.fr       */
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
	if (pthread_mutex_init(&mutex->death, NULL) != 0)
		return (mutex_init_failed());
	if (pthread_mutex_init(&mutex->printf, NULL) != 0)
		return (mutex_init_failed());
	if (pthread_mutex_init(&mutex->counter, NULL) != 0)
		return (mutex_init_failed());
	mutex->d_trig = 0;
	mutex->count = 0;
	return (0);
}

int	thread(t_data data, t_philo *philo, t_mutex *mutex)
{
	if (philo == NULL)
	{
		printf("Error\n");
		printf("Malloc Failed\n");
		free(mutex);
		return (1);
	}
	if (data.nb_philo == 1)
	{
		if (sadly_alone_guy(data, philo, mutex) == 1)
		{
			free(philo);
			free(mutex);
			return (1);
		}
	}
	else
	{
		if (create_thread(data, philo, mutex) == 1)
		{
			free(philo);
			free(mutex);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;
	t_mutex	*mutex;
	int		i;

	i = 0;
	mutex = malloc(sizeof(t_mutex));
	if (init_mutex(mutex) == 1)
		return (1);
	if (parsing(argc, argv) == 0)
	{
		data = init_data(argc, argv);
		if (check_max(data) == 1 || check_nb_philo(data) == 1)
			return (1);
		data.time_start = get_time();
		philo = malloc(sizeof(t_philo) * data.nb_philo);
		if (thread(data, philo, mutex) == 1)
			return (1);
		while (i != data.nb_philo)
		{
			pthread_join(philo[i].thread_philo, NULL);
			i ++;
		}
		free(philo);
	}
	free(mutex);
	return (0);
}
