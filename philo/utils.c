/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:44:15 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/21 01:33:45 by nkalkoul         ###   ########.fr       */
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
				("Error argument: only positif and valid number requir\n"), -1);
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	if (nb > 2147483647)
		return (printf("Error argument: only number less than int max\n"), -1);
	return (nb);
}

long ft_current_time_in_ms(void)
{
	struct timeval yo;
	long val;

	gettimeofday(&yo, NULL);
	val = (yo.tv_sec * 1000) + yo.tv_usec / 1000;
	return (val);
}

void	ft_printf(t_philo *ph, char *msg)
{
	long	time;

	pthread_mutex_lock(&ph->data->print);
	time = ft_current_time_in_ms();
	printf("%ld %d %s\n", time - ph->data->start_time, ph->id, msg);
	pthread_mutex_unlock(&ph->data->print);
}
