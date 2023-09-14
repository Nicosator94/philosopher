/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:01:57 by niromano          #+#    #+#             */
/*   Updated: 2023/09/14 10:07:19 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	ms;
	long	time;

	gettimeofday(&ms, NULL);
	time = (ms.tv_sec * 1000) + (ms.tv_usec / 1000);
	return (time);
}
