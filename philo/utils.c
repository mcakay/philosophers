/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:13:22 by mcakay            #+#    #+#             */
/*   Updated: 2022/10/05 15:33:39 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//It takes a string and returns the number it represents
long	ft_atol(const char *s)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (*(s + i) == ' ' || (*(s + i) >= 9 && *(s + i) <= 13))
		i++;
	if (*(s + i) == '-' || *(s + i) == '+')
	{
		if (*(s + i) == '-')
			sign = -sign;
		i++;
	}
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		num = (num * 10) + (*(s + i) - 48);
		i++;
	}
	return (num * sign);
}