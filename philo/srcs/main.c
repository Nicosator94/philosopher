/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 10:53:41 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	init_data(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	data.nb_philo = ft_atoi(argv[1]);
	data.t_die = ft_atoi(argv[2]);
	data.t_eat = ft_atoi(argv[3]);
	data.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.nb_t_eat = ft_atoi(argv[5]);
	else
		data.nb_t_eat = -1;
	data.philo = malloc(sizeof(t_philo) * data.nb_philo);
	if (data.philo != NULL)
	{
		while (i != data.nb_philo)
		{
			data.philo[i].num = i + 1;
			i ++;
		}
	}
	else
		printf("Error Malloc\n");
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data			data;
	// struct timeval	*ms;

	// ms = malloc(sizeof(struct timeval));
	// printf("%d\n", gettimeofday(ms, NULL));
	// printf("%ld\n", ms->tv_usec);
	// free(ms);
	if (parsing(argc, argv) == 0)
	{
		data = init_data(argc, argv);
		if (check_max(data) == 1 || check_nb_philo(data) == 1 || data.philo == NULL)
		{
			if (data.philo != NULL)
				free(data.philo);
			return (0);
		}
		printf("Number of philosophers : %ld\n", data.nb_philo);
		printf("Time before dying : %ld\n", data.t_die);
		printf("Time to eat : %ld\n", data.t_eat);
		printf("Time to sleep : %ld\n", data.t_sleep);
		if (argc == 6)
			printf("Number of times philosophers have to eat : %ld\n", data.nb_t_eat);
		if (create_thread(data) == 1)
			return (0);
		free(data.philo);
	}
	return (0);
}
