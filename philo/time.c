/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:07:36 by mcakay            #+#	    #+#             */
/*   Updated: 2022/10/09 13:58:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It sleeps for a certain amount of time
void	ft_sleep(t_philo *philo, int wait_time)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)wait_time)
	{
		ft_check_death(philo);
		usleep(100);
	}
}

//It returns the current time in milliseconds
t_time	ft_get_time(void)
{
	struct timeval		tv;
	t_time				time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
