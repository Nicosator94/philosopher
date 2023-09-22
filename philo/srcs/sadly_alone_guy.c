/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sadly_alone_guy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:10:24 by niromano          #+#    #+#             */
/*   Updated: 2023/09/22 13:23:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*fn_alone(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->mutex->printf);
	printf("%lld %d is thinking\n", get_time() - philo->data.time_start, philo->number);
	pthread_mutex_unlock(&philo->mutex->printf);
	usleep(philo->data.t_die * 1000);
	pthread_mutex_lock(&philo->mutex->printf);
	printf("%lld %d died\n", get_time() - philo->data.time_start, philo->number);
	pthread_mutex_unlock(&philo->mutex->printf);
	return (0);
}

void	sadly_alone_guy(t_data data, t_philo *philo, t_mutex *mutex)
{
	philo[0].data = copy_data(data);
	philo[0].number = 1;
	philo[0].actu_time = 0;
	philo[0].before_die = 0;
	philo[0].old_die = 0;
	philo[0].count = 0;
	philo[0].mutex = mutex;
	pthread_mutex_init(&philo[0].fork.fork, NULL);
	pthread_create(&philo[0].thread_philo, NULL, fn_alone, &philo[0]);
}
