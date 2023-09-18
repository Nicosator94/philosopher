/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/09/18 08:16:22 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;
	int		i;

	i = 0;
	if (parsing(argc, argv) == 0)
	{
		data = init_data(argc, argv);
		if (check_max(data) == 1 || check_nb_philo(data) == 1)
			return (0);
		data.time_start = get_time();
		philo = malloc(sizeof(t_philo) * data.nb_philo);
		if (create_thread(data, philo) == 1)
			return (0);
		while (i != data.nb_philo)
		{
			pthread_join(philo[i].thread_philo, NULL);
			i ++;
		}
		free(philo);
	}
	return (0);
}
