/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:51:14 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/24 08:56:49 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_whenis_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->is_died);
	if (ph->data->died_or_alive == DEAD)
	{
		pthread_mutex_unlock(&ph->data->is_died);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->is_died);
	return (0);
}

int	ft_take_fork(t_philo *ph)
{
	if (ph->id % 2 == 0 || ph->data->nb_philos % 2 != 0)
	{
		if (ft_pair(ph) == 1)
			return (1);
	}
	else
	{
		if (ft_impair(ph) == 1)
			return (1);
	}
	return (0);
}

int	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->eat_last);
	ph->last_eat = ft_current_time();
	pthread_mutex_unlock(&ph->eat_last);
	if (ft_printf(ph, " is eating", 0) == 1)
		return (ft_drop_fork(ph), 1);
	if (ft_usleep(ph, ph->data->tteat) == 1)
		return (ft_drop_fork(ph), 1);
	pthread_mutex_lock(&ph->have_eat);
	ph->nb_eat++;
	pthread_mutex_unlock(&ph->have_eat);
	return (0);
}

void	ft_drop_fork(t_philo *ph)
{
	if (ph->id % 2 == 0 || ph->data->nb_philos % 2 != 0)
	{
		pthread_mutex_unlock(&ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
	}
	else
	{
		pthread_mutex_unlock(ph->r_fork);
		pthread_mutex_unlock(&ph->l_fork);
	}
}

int	ft_sleep(t_philo *ph)
{
	if (ft_printf(ph, "is sleeping", 0) == 1)
		return (1);
	if (ft_usleep(ph, ph->data->ttsleep) == 1)
		return (1);
	if (ft_whenis_dead(ph) == 1)
		return (1);
	return (0);
}
