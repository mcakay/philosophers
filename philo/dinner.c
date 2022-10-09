/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:49:23 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/09 17:34:25 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lonely_dinner(t_philo *philo)
{
	while (1)
		ft_check_death(philo);
}

void *ft_dinner(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(philo->left_fork_mutex);
		ft_print_status(philo, "has taken a fork");
		if (philo->philo_nb == 1)
			ft_lonely_dinner(philo);
		pthread_mutex_lock(philo->right_fork_mutex);
		ft_print_status(philo, "has taken a fork");
		ft_print_status(philo, "is eating");
		ft_sleep(philo, philo->time_to_eat);
		ft_print_status(philo, "is sleeping");
		philo->last_meal = ft_get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->right_fork_mutex);
		pthread_mutex_unlock(philo->left_fork_mutex);
		ft_sleep(philo, philo->time_to_sleep);
		ft_print_status(philo, "is thinking");
	}
	return (NULL);
}
