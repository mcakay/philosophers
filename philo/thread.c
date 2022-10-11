/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:05:47 by  mcakay           #+#    #+#             */
/*   Updated: 2022/10/12 02:46:22 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_join_threads(t_philo *philo, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, &philo[i]);
		i++;
		usleep(100);
	}
	while (*philo->is_dead != 1)
		ft_check_death(philo);
}
