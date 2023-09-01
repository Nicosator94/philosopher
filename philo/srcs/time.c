/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:01:57 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 15:20:17 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	set_time(void)
{
	struct timeval	ms;
	unsigned long	time;

	gettimeofday(&ms, NULL);
	time = (ms.tv_sec * 1000) + (ms.tv_usec / 1000);
	return (time);
}

long	actualize_time(void *arg)
{
	struct timeval	ms;
	long	time_start;
	long	time_now;

	time_start = (unsigned long)arg;
	gettimeofday(&ms, NULL);
	time_now = (ms.tv_sec * 1000) + (ms.tv_usec / 1000) - time_start;
	return (time_now);
}
