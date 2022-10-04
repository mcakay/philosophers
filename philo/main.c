/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:12:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/04 08:07:41 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*root;

	if (argc != 5 && argc != 6)
		return (1);
	ft_init_data(&data, argv);
	ft_init_philos(&data, &root);
	while (root)
	{
		printf("%lld\n", root->start_time);
		root = root->next;
	}
	return (0);
}
