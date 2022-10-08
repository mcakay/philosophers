/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:51:56 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 18:46:21 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lock_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_lock(&philo[i].death);
		i++;
	}
}

void	ft_unlock_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_nb)
	{
		pthread_mutex_unlock(&philo[i].death);
		i++;
	}
}