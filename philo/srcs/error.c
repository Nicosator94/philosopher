/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:07:07 by niromano          #+#    #+#             */
/*   Updated: 2023/09/25 08:13:01 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	mutex_init_failed(void)
{
	printf("Error\n");
	printf("Mutex initialization failed\n");
	return (1);
}

int	thread_create_failed(void)
{
	printf("Error\n");
	printf("Thread creation failed\n");
	return (1);
}
