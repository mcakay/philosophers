/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:01:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/11 14:34:06 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It checks if the philosopher has died
void	ft_check_death(t_philo *philo)
{
	t_time	time;
	int		i;

	
	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_lock(philo->death);
		time = ft_get_time() - philo[i].last_meal;
		if ((int)time > philo[i].time_to_die)
		{
			printf("%llu %d %s\n", time, philo->id + 1, "died");
			*philo->is_dead = 1;
			break ;
		}
		i++;
		pthread_mutex_unlock(philo->death);
	}
}

//It prints the time, the id of the philosopher, and the status of the philosopher
int	ft_print_status(t_philo *philo, char *status)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%llu %d %s\n", time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
	return (0);
}
