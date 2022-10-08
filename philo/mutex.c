/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:05:15 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 13:12:54 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It initializes the mutexes for each philosopher
void	ft_init_mutex(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(&philo[i].mutex, NULL);
		pthread_mutex_init(&philo[i].mutex_write, NULL);
		i++;
	}
}

pthread_mutex_t	*ft_init_forks_mutex(char **argv)
{
	int				i;
	pthread_mutex_t *forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(argv[1]));
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}