/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:01:57 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 12:54:44 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*actualize_time(void *arg)
{
	struct timeval	*ms;
	t_data			*data;

	data = (t_data *)arg;
	ms = malloc(sizeof(struct timeval));
	gettimeofday(ms, NULL);
	data->time.start = (ms->tv_sec * 1000) + (ms->tv_usec / 1000);
	data->time.stop = 0;
	while (data->time.stop != 1)
	{
		gettimeofday(ms, NULL);
		data->time.now = (ms->tv_sec * 1000) + (ms->tv_usec / 1000) - data->time.start;
		//printf("\n%ld", data->time.now);
		if (data->time.now > 4000)
			data->time.stop = 1;
	}
	free(ms);
	pthread_exit(EXIT_SUCCESS);
}
