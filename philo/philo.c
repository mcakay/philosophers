/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:33:51 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/06 06:17:59 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// It creates a new philosopher, creates a thread for it, and returns it
static t_philo	*ft_create_philo(t_data *data, int *id, t_time start_time, pthread_mutex_t *forks)
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
	new->forks = forks;
	new->data = data;
	if (*id == 1)
		new->left_fork = data->number_of_philosophers;
	pthread_create(&new->thread, NULL, &ft_dinner_time, new);
	pthread_mutex_init(&new->lock, NULL);
	new->next = NULL;
	(*id)++;
	return (new);
}

//It creates a linked list of philosophers
static void	ft_add_philo(t_data *data, t_philo **root, int *id, t_time start_time, pthread_mutex_t *forks)
{
	t_philo	*curr;

	if (*root == NULL)
	{
		*root = ft_create_philo(data, id, start_time, forks);
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = ft_create_philo(data, id, start_time, forks);
	if (*id == data->number_of_philosophers + 1)
		curr->next->next = *root;
}

//It initializes the philosophers
void	ft_init_philos(t_data *data, t_philo **root)
{
	struct timeval	tv;
	t_time			start_time;
	int				id;
	pthread_mutex_t	*forks;
	int				i;

	id = 1;
	gettimeofday(&tv, NULL);
	start_time = tv.tv_sec;
	forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(forks + i, NULL);
		i++;
	}
	while (id <= data->number_of_philosophers)
		ft_add_philo(data, root, &id, start_time, forks);
}