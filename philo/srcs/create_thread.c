/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 12:54:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*test(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%d\n", philo->number);
	pthread_exit(EXIT_SUCCESS);
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
		pthread_create(&philo[i].thread_philo, NULL, test, &philo[i]);
		i ++;
	}
	return (0);
}
