/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:02:12 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/04 11:00:03 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_dinner_time(void *arg)
{
	(void)arg;
	printf("Yemek\n");
	return ((void *)0);
}

void	ft_dinner_join(t_data data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}
