/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/07/29 07:05:05 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	init_data(int argc, char *argv[])
{
	t_data	data;

	data.nb_philo = ft_atoi(argv[1]);
	data.t_die = ft_atoi(argv[2]);
	data.t_eat = ft_atoi(argv[3]);
	data.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.nb_t_eat = ft_atoi(argv[5]);
	return (data);
}

int main(int argc, char *argv[])
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
		printf("Number of philosophers : %d\n", data.nb_philo);
		printf("Time before dying : %d\n", data.t_die);
		printf("Time to eat : %d\n", data.t_eat);
		printf("Time to sleep : %d\n", data.t_sleep);
		if (argc == 6)
			printf("Number of times philosophers have to eat : %d\n", data.nb_t_eat);
	}
	return (0);
}
