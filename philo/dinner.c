/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:02:12 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/06 06:22:23 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_dinner_time(void *arg)
{
	t_philo *philo;

	philo = (t_philo*)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->right_fork - 1]);
		printf("%d has taken a fork\n", philo->id);
		pthread_mutex_lock(&philo->forks[philo->left_fork - 1]);
		printf("%d is eating\n", philo->id);
		usleep(philo->data->time_to_eat * 500);
		printf("%d is sleeping\n", philo->id);
		pthread_mutex_unlock(&philo->forks[philo->right_fork - 1]);
		pthread_mutex_unlock(&philo->forks[philo->left_fork - 1]);
		usleep(philo->data->time_to_sleep * 500);
		printf("%d is thinking\n", philo->id);
	}
	return ((void *)0);
}

void	ft_join_dinner(t_philo **root)
{
	t_philo *curr;
	int	i;

	i = 0;
	curr = *root;
	while (i < (*root)->data->number_of_philosophers)
	{
		pthread_join(curr->thread, NULL);
		i += 2;
		curr = curr->next->next;
	}
	i = 1;
	curr = *root;
	while (i < (*root)->data->number_of_philosophers)
	{
		pthread_join(curr->thread, NULL);
		i += 2;
		curr = curr->next->next;
	}
}
