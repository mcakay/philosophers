/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:01:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/09 16:38:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It checks if the philosopher has died
void	ft_check_death(t_philo *philo)
{
	t_time	time;

	time = ft_get_time() - philo->last_meal;
	pthread_mutex_lock(philo->death);
	if ((int)time > philo->time_to_die)
	{
		printf("%llu %d %s\n", time, philo->id + 1, "died");
		exit(0);
	}
	pthread_mutex_unlock(philo->death);
}

//It prints the time, the id of the philosopher, and the status of the philosopher
void	ft_print_status(t_philo *philo, char *status)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;

	ft_check_death(philo);
	printf("%llu %d %s\n", time, philo->id + 1, status);
}
