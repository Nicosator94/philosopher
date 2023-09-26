/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:37:13 by niromano          #+#    #+#             */
/*   Updated: 2023/09/26 07:38:42 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*fn_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	mutex_printf(philo, "%lld %d is thinking\n");
	if (philo->number % 2 == 0)
		usleep(100);
	while (1)
	{
		usleep(20);
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
	}
	return (NULL);
}
