/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:12:28 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/04 10:56:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef long long t_time;

typedef struct s_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosoper_must_eat;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				is_dead;
	t_time			start_time;
	t_time			last_eat_time;
	int				left_fork;
	int				right_fork;
	pthread_t 		thread;
	struct s_philo	*next;
}				t_philo;

//utils
long	ft_atol(const char *s);

//data
void	ft_init_data(t_data *data, char **argv);

//philo
void	ft_init_philos(t_data data, t_philo **root);

//dinner
void	*ft_dinner_time(void *arg);
void	ft_dinner_join(t_data data, t_philo *philo);

#endif