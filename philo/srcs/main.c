/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:17:06 by niromano          #+#    #+#             */
/*   Updated: 2023/09/27 11:15:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_mutex	*mutex;

	mutex = malloc(sizeof(t_mutex));
	if (init_mutex(mutex) == 1)
		return (1);
	if (parsing(argc, argv) == 0)
	{
		data = init_data(argc, argv);
		if (ft_philo(data, mutex) == 1)
			return (1);
	}
	destroy_mutex(mutex);
	return (0);
}
