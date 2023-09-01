/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:47:52 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 10:53:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*test(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%d\n", philo->num);
	pthread_exit(EXIT_SUCCESS);
}

int	create_thread(t_data data)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i != data.nb_philo)
	{
		if (pthread_create(&thread, NULL, test, &data.philo[i]) != 0)
		{
			free(data.philo);
			printf("Error System\n");
			return (1);
		}
		if (pthread_join(thread, NULL) != 0)
		{
			free(data.philo);
			printf("Error System\n");
			return (1);
		}
		i ++;
	}
	return (0);
}
