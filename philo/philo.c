/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:06:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 21:11:28 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It initializes the philosophers
void	ft_init_philos(t_philo *philo, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atol(argv[2]);
		philo[i].time_to_eat = ft_atol(argv[3]);
		philo[i].time_to_sleep = ft_atol(argv[4]);
		if (argc == 6)
			philo[i].must_eat = ft_atol(argv[5]);
		else
			philo[i].must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].meals_eaten = 0;
		philo[i].philo_nb = ft_atol(argv[1]);
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % ft_atol(argv[1]);
		i++;
	}
}
