/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/15 14:09:50 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->next_fork);
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, 1);
	mutex_printf(philo, 1);
	mutex_printf(philo, 2);
	while (get_time() - (philo->data.time_start + philo->actu_time) != philo->data.t_eat) {}
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(&philo->fork);
	philo->actu_time = get_time() - philo->data.time_start;
	mutex_printf(philo, 3);
	while (get_time() - (philo->data.time_start + philo->actu_time) != philo->data.t_sleep) {}
	mutex_printf(philo, 4);
	return (0);
}

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	mutex_printf(philo, 4);
	while (1)
	{
		eating(philo);
		// if(pthread_mutex_destroy(&philo->fork) != 0)
		// {
		// 	pthread_mutex_unlock(&philo->fork);
		// 	pthread_mutex_destroy(&philo->fork);
		// }
		// return (NULL);
	}
	return (NULL);
}

t_data	copy_data(t_data data)
{
	t_data	copy_data;
	pthread_mutex_t	m_printf;

	pthread_mutex_init(&m_printf, NULL);
	copy_data.nb_philo = data.nb_philo;
	copy_data.t_die = data.t_die;
	copy_data.t_eat = data.t_eat;
	copy_data.t_sleep = data.t_sleep;
	copy_data.nb_t_eat = data.nb_t_eat;
	copy_data.time_start = data.time_start;
	copy_data.m_printf = &m_printf;
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
		philo[i].actu_time = 0;
		pthread_mutex_init(&philo[i].fork, NULL);
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
