/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 15:16:34 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("nb = %d ici = %ld\n", philo->number, philo->data->time_start);
	// printf("%ld %d has taken a fork\n", actualize_time(&philo->data->time_start), philo->number);
	// printf("%ld %d is eating\n", actualize_time(&philo->data->time_start), philo->number);
	// printf("%ld %d is sleeping\n", actualize_time(&philo->data->time_start), philo->number);
	// printf("%ld %d is thinking\n", actualize_time(&philo->data->time_start), philo->number);
	// printf("%ld %d is died\n", actualize_time(&philo->data->time_start), philo->number);
	// printf("nb = %d\n", philo->number);
	// printf("fork = %d\n", philo->fork);
	// printf("next = %d\n", *philo->next_fork);
	// pthread_exit(EXIT_SUCCESS);
	return (NULL);
}

int	create_thread(t_data data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i != data.nb_philo)
	{
		philo[i].data = &data;
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
