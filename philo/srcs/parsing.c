/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 07:01:10 by niromano          #+#    #+#             */
/*   Updated: 2023/07/29 07:15:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		printf("Error : Not enough arguments !\n");
		printf("The arguments asked looks like :\n");
		printf("1 : Number of philosophers\n");
		printf("2 : Time before dying\n");
		printf("3 : Time to eat\n");
		printf("4 : time to sleep\n");
		printf("And optionally\n");
		printf("5 : Number of times philosophers have to eat\n");
		return (1);
	}
	else if (check_chara(argc, argv) == 1)
	{
		printf("Error : Arguments include things other than numbers !\n");
		return (1);
	}
	return (0);
}
