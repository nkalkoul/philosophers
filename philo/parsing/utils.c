/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:44:15 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/25 13:35:23 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

long	ft_current_time(void)
{
	struct timeval	yo;
	long			val;

	gettimeofday(&yo, NULL);
	val = (yo.tv_sec * 1000) + yo.tv_usec / 1000;
	return (val);
}

int	ft_printf(t_philo *ph, char *msg, int monitor)
{
	long	time;

	pthread_mutex_lock(&ph->data->print);
	if (ft_whenis_dead(ph) == 1 && monitor == 0)
	{
		pthread_mutex_unlock(&ph->data->print);
		return (1);
	}
	time = ft_current_time();
	printf("%ld %d %s\n", time - ph->data->start_time, ph->id, msg);
	pthread_mutex_unlock(&ph->data->print);
	return (0);
}

void	ft_end_mutex(t_philo *ph)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&ph->data->is_died);
	pthread_mutex_destroy(&ph->data->print);
	while (i < ph->data->nb_philos)
	{
		pthread_mutex_destroy(&ph[i].eat_last);
		pthread_mutex_destroy(&ph[i].l_fork);
		pthread_mutex_destroy(&ph[i].have_eat);
		i++;
	}
	free(ph);
}

int	ft_usleep(t_philo *ph, long time)
{
	long	actual;

	actual = ft_current_time();
	while (1)
	{
		if (ft_whenis_dead(ph) == 1)
			return (1);
		usleep(100);
		if (ft_current_time() - actual >= time / 1000)
			break ;
	}
	return (0);
}
