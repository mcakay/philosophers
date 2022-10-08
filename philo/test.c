/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:06:33 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/08 21:12:04 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void mutext_tester(t_philo *list)
{
	int i = 0;
	while (i < list->philo_nb)
	{
		printf("left fork : %p right fork : %p\n",&list[i].left_fork_mutex, &list[i].right_fork_mutex);
		i++;
	}
}