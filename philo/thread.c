/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:05:47 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 21:27:57 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It joins all the threads
void ft_join_threads(t_philo *philo, char **argv)
{
	int i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, NULL);
		pthread_detach(philo[i].thread);
		i += 2;
	}
	i = 1;
	while (i < ft_atol(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_dinner, NULL);
		pthread_detach(philo[i].thread);
		i += 2;
	}
}