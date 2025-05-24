/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:19:05 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/24 08:59:41 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_one_fork(t_philo *ph, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (ft_whenis_dead(ph) == 1)
	{
		pthread_mutex_unlock(fork);
		return (1);
	}
	if (ft_printf(ph, "has taken a fork", 0) == 1)
	{
		pthread_mutex_unlock(fork);
		return (1);
	}
	return (0);
}

int	ft_impair(t_philo *ph)
{
	if (ft_one_fork(ph, &ph->l_fork) == 1)
		return (1);
	if (ft_one_fork(ph, ph->r_fork) == 1)
	{
		pthread_mutex_unlock(&ph->l_fork);
		return (1);
	}
	return (0);
}

int	ft_pair(t_philo *ph)
{
	if (ft_one_fork(ph, ph->r_fork) == 1)
		return (1);
	if (ft_one_fork(ph, &ph->l_fork) == 1)
	{
		pthread_mutex_unlock(ph->r_fork);
		return (1);
	}
	return (0);
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

void	*ft_routine1(void *arg)
{
	t_philo	*ph;

	ph = arg;
	ph->data->start_time = ft_current_time();
	ft_printf(ph, "has taken a fork", 0);
	usleep(ph->data->ttdie);
	ft_printf(ph, "died", 0);
	return (arg);
}
