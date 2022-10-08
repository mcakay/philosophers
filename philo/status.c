/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:01:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 15:19:21 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It checks if the philosopher has died
void	ft_check_death(t_philo *philo)
{
	t_time	time;

	time = ft_get_time() - philo->last_meal;
	if ((int)time > philo->time_to_die)
	{
		ft_print_status(philo, "died");
		exit(0);
	}
}

//It prints the time, the id of the philosopher, and the status of the philosopher
void	ft_print_status(t_philo *philo, char *status)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;
	printf("%llu %d %s\n", time, philo->id, status);
}