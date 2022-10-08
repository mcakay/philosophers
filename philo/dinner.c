/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:49:23 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 20:59:08 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_dinner(void *args)
{
	t_philo *philo;

	philo = (t_philo *)args;
	while (1)
	{
		ft_print_status(philo, "has taken a fork");
		ft_print_status(philo, "has taken a fork");
		ft_print_status(philo, "is eating");
		ft_sleep(philo, philo->time_to_eat);
		philo->last_meal = ft_get_time();
		philo->meals_eaten++;
		ft_print_status(philo, "is sleeping");
		ft_sleep(philo, philo->time_to_sleep);
		ft_print_status(philo, "is thinking");
	}
}
