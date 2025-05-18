/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:44:15 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/17 03:58:31 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (printf
				("Error argument: only positif and valid number required"), -1);
		nb = nb * 10 + (s[i] - 48);
	}
	if (nb > 2147483647)
		return (printf("Error argument: only number less than int max"), -1);
	return (nb);
}
