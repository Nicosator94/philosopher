/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/07/18 09:46:22 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	init_data(int argc, char *argv[])
{
	t_data	data;

	data.nb_philo = argv[1];
	data.t_die = argv[2];
	data.t_eat = argv[3];
	data.t_sleep = argv[4];
	data.nb_t_eat = argv[5];
	return (data);
}

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 6)
	{
		data = init_data(argc, argv);
	}
	else
		printf("argv nul\n");
	return (0);
}
