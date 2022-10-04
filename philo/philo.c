/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:33:51 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/04 10:59:55 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*ft_create_philo(t_data data, int *id, t_time start_time)
{
	t_philo		*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = *id;
	new->eat_count = 0;
	new->is_dead = 0;
	new->start_time = start_time;
	new->right_fork = *id;
	new->left_fork = *id - 1;
	pthread_create(&new->thread, NULL, &ft_dinner_time, NULL);
	if (*id == 1)
		new->left_fork = data.number_of_philosophers;
	new->next = NULL;
	(*id)++;
	return (new);
}

static void	ft_add_philo(t_data data, t_philo **root, int *id, t_time start_time)
{
	t_philo	*curr;

	if (*root == NULL)
	{
		*root = ft_create_philo(data, id, start_time);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = ft_create_philo(data, id, start_time);
	if (*id == data.number_of_philosophers + 1)
		curr->next->next = *root;
}

void	ft_init_philos(t_data data, t_philo **root)
{
	struct timeval	tv;
	t_time			start_time;
	int				id;

	id = 1;
	gettimeofday(&tv, NULL);
	start_time = tv.tv_sec;
	while (id <= data.number_of_philosophers)
		ft_add_philo(data, root, &id, start_time);
}