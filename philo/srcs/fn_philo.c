/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:37:13 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 10:38:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	sleep_think(t_philo *philo)
{
	int	comp;

	comp = philo->data.t_die - philo->data.t_eat * 3;
	if (comp < 0)
		comp = -comp;
	if (comp >= 0 && philo->data.t_eat >= philo->data.t_sleep
		&& philo->data.nb_philo % 2 == 1)
	{
		while (get_time() - (philo->data.time_start
				+ philo->actu_time) < philo->data.t_eat)
		{
			if (check_death(philo) == 1)
				return (1);
			usleep(50);
		}
	}
	else
		usleep(20);
	return (0);
}

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	mutex_printf(philo, "%lld %d is thinking\n");
	if (philo->number % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo->number % 2 == 0)
		{
			if (cycle_for_even(philo) == 1)
				return (NULL);
		}
		else
		{
			if (cycle_for_odd(philo) == 1)
				return (NULL);
		}
		if (check_death(philo) == 1)
			return (NULL);
		if (sleep_think(philo) == 1)
			return (NULL);
	}
	return (NULL);
}
