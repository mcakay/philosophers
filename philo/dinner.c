/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:49:23 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/12 02:54:21 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_lonely_dinner(t_philo *philo)
{
	ft_sleep(philo->time_to_die);
	return (1);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	if (ft_print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		return (1);
	}
	if (philo->philo_nb == 1)
		if (ft_lonely_dinner(philo))
			return (1);
	pthread_mutex_lock(philo->right_fork_mutex);
	if (ft_print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->right_fork_mutex);
		pthread_mutex_unlock(philo->left_fork_mutex);
		return (1);
	}
	if (ft_print_status(philo, "is eating"))
	{
		pthread_mutex_unlock(philo->right_fork_mutex);
		pthread_mutex_unlock(philo->left_fork_mutex);
		return (1);
	}
	return (0);
}

int	ft_sleep_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	philo->meals_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->death);
	ft_sleep(philo->time_to_eat);
	if (ft_print_status(philo, "is sleeping"))
	{
		pthread_mutex_unlock(philo->right_fork_mutex);
		pthread_mutex_unlock(philo->left_fork_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->right_fork_mutex);
	pthread_mutex_unlock(philo->left_fork_mutex);
	ft_sleep(philo->time_to_sleep);
	return (0);
}

void	*ft_dinner(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (ft_eat(philo))
			break ;
		if (ft_sleep_philos(philo))
			break ;
		if (ft_print_status(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
