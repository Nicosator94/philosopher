/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:59:22 by niromano          #+#    #+#             */
/*   Updated: 2023/09/15 14:07:44 by niromano         ###   ########.fr       */
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
	else
		data.nb_t_eat = -1;
	return (data);
}
