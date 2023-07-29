/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:11:16 by niromano          #+#    #+#             */
/*   Updated: 2023/07/29 07:04:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_data
{
	int	nb_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_t_eat;
}				t_data;

int	parsing(int argc, char *argv[]);
int	ft_atoi(const char *nptr);

#endif