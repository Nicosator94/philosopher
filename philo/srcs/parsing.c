/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:01:10 by niromano          #+#    #+#             */
/*   Updated: 2023/09/01 08:40:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_max(t_data data)
{
	int	trigger;
	int	int_max;

	trigger = 0;
	int_max = 2147483647;
	if (data.nb_philo > int_max || data.t_die > int_max || data.t_eat > int_max
		|| data.t_sleep > int_max || data.nb_t_eat > int_max)
		trigger = 1;
	if (trigger == 1)
	{
		printf("Error\n");
		printf("A given variable exceeds the max int !\n");
		return (1);
	}
	return (0);
}

int	check_nb_philo(t_data data)
{
	if (data.nb_philo == 0)
	{
		printf("Error\n");
		printf("There are no philosophers !\n");
		return (1);
	}
	return (0);
}

int	check_chara(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	parsing(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\n");
		printf("Not enough arguments !\n\n");
		printf("The arguments asked looks like :\n");
		printf("1 : Number of philosophers\n");
		printf("2 : Time before dying\n");
		printf("3 : Time to eat\n");
		printf("4 : time to sleep\n\n");
		printf("And optionally\n");
		printf("5 : Number of times philosophers have to eat\n");
		return (1);
	}
	else if (check_chara(argc, argv) == 1)
	{
		printf("Error\n");
		printf("Arguments include things other than numbers !\n");
		return (1);
	}
	return (0);
}
