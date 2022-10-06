/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:12:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/06 03:46:15 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//It initializes the data structure, then initializes the philosophers
int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*root;

	if (argc != 5 && argc != 6)
		return (1);
	ft_init_data(&data, argv);
	ft_init_philos(&data, &root);
	ft_join_dinner(&root);
	return (0);
}
