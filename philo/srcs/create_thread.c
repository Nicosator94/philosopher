/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/14 10:07:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%ld %d has taken a fork\n", get_time() - philo->data.time_start, philo->number);
	// printf("%ld %d is eating\n", actualize_time(&philo->data.time_start), philo->number);
	// printf("%ld %d is sleeping\n", actualize_time(&philo->data.time_start), philo->number);
	// printf("%ld %d is thinking\n", actualize_time(&philo->data.time_start), philo->number);
	// printf("%ld %d is died\n", actualize_time(&philo->data.time_start), philo->number);
	pthread_exit(EXIT_SUCCESS);
	return (NULL);
}

t_data	copy_data(t_data data)
{
	t_data	copy_data;

	copy_data.nb_philo = data.nb_philo;
	copy_data.t_die = data.t_die;
	copy_data.t_eat = data.t_eat;
	copy_data.t_sleep = data.t_sleep;
	copy_data.nb_t_eat = data.nb_t_eat;
	copy_data.time_start = data.time_start;
	return (copy_data);
}

int	create_thread(t_data data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i != data.nb_philo)
	{
		philo[i].data = copy_data(data);
		philo[i].number = i + 1;
		philo[i].number_eat = 0;
		philo[i].fork = 1;
		i ++;
	}
	i = 0;
	while (i != data.nb_philo)
	{
		if (i + 1 == data.nb_philo)
			philo[i].next_fork = &philo[0].fork;
		else
			philo[i].next_fork = &philo[i + 1].fork;
		i ++;
	}
	i = -1;
	while (i++ != data.nb_philo - 1)
		pthread_create(&philo[i].thread_philo, NULL, fn_philo, &philo[i]);
	return (0);
}
