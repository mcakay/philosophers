/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:05:15 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/10 19:25:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It initializes the mutexes for each philosopher
void	ft_init_mutex(t_philo *philo, char **argv)
{
	int	i;
	pthread_mutex_t *forks;
	pthread_mutex_t *death;
	pthread_mutex_t *print;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * philo->philo_nb);
	while (i < philo->philo_nb)
	{
		philo[i].left_fork_mutex = &forks[i];
		philo[i].right_fork_mutex = &forks[(i + 1) % philo->philo_nb];
		i++;
	}
	i = 0;
	death = malloc(sizeof(pthread_mutex_t));
	print = malloc(sizeof(pthread_mutex_t));
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(philo[i].left_fork_mutex, NULL);
		pthread_mutex_init(philo[i].right_fork_mutex, NULL);
		philo[i].death = death;
		philo[i].print = print;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
	pthread_mutex_init(philo->print, NULL);
}