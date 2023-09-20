/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/09/20 12:07:56 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_mutex(t_mutex *mutex)
{
	pthread_mutex_init(&mutex->death, NULL);
	pthread_mutex_init(&mutex->printf, NULL);
	pthread_mutex_init(&mutex->counter, NULL);
	mutex->d_trig = 0;
	mutex->count = 0;
}

void	thread(t_data data, t_philo *philo, t_mutex *mutex)
{
	if (data.nb_philo == 1)
		sadly_alone_guy(data, philo, mutex);
	else
		create_thread(data, philo, mutex);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;
	t_mutex	*mutex;
	int		i;

	i = 0;
	mutex = malloc(sizeof(t_mutex));
	init_mutex(mutex);
	if (parsing(argc, argv) == 0)
	{
		data = init_data(argc, argv);
		if (check_max(data) == 1 || check_nb_philo(data) == 1)
			return (0);
		data.time_start = get_time();
		philo = malloc(sizeof(t_philo) * data.nb_philo);
		thread(data, philo, mutex);
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
