#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				philo_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	int				meals_eaten;
	int				left_fork;
	int				right_fork;
	t_time			last_meal;
	t_time			start_time;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	pthread_mutex_t	death;
	pthread_mutex_t	mutex_write;
}				t_philo;

//time
t_time	ft_get_time(void);
void	ft_sleep(int wait_time);

//check
int		ft_check_args(int argc, char **argv);

//philo
void	ft_init_philos(t_philo *philo, int argc, char **argv);

//mutex
void			ft_init_mutex(t_philo *philo, char **argv);
pthread_mutex_t	*ft_init_forks_mutex(char **argv);

//utils
long	ft_atol(const char *str);

//status
void	ft_print_status(t_philo *philo, char *status);
void	ft_check_death(t_philo *philo);

//dinner
void	*ft_dinner(void *args);

//thread
void	ft_join_threads(t_philo *philo, char **argv);

#endif