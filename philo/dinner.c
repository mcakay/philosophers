/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:49:23 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/10 03:41:01 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lonely_dinner(t_philo *philo)
{
	while (1)
		ft_check_death(philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	ft_print_status(philo, "has taken a fork");
	if (philo->philo_nb == 1)
		ft_lonely_dinner(philo);
	pthread_mutex_lock(philo->right_fork_mutex);
	ft_print_status(philo, "has taken a fork");
	ft_print_status(philo, "is eating");
	philo->last_meal = ft_get_time();
	ft_sleep(philo, philo->time_to_eat);
}

void	ft_sleep_philos(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	pthread_mutex_unlock(philo->right_fork_mutex);
	pthread_mutex_unlock(philo->left_fork_mutex);
	ft_sleep(philo, philo->time_to_sleep);
}

void *ft_dinner(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (1)
	{
		ft_eat(philo);
		ft_sleep_philos(philo);
		ft_print_status(philo, "is thinking");
	}
	return (NULL);
}
