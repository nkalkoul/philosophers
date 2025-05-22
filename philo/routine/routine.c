/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:51:14 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/22 04:54:15 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_take_fork(t_philo *ph)
{
	if (ph->id % 2 == 1)
	{
		pthread_mutex_lock(&ph->l_fork);
		ft_printf(ph, "has taken a fork");
		pthread_mutex_lock(ph->r_fork);
		ft_printf(ph, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(ph->r_fork);
		ft_printf(ph, "has taken a fork");
		pthread_mutex_lock(&ph->l_fork);
		ft_printf(ph, "has taken a fork");
	}
}

void	ft_eat(t_philo *philos)
{
	philos->last_eat = ft_current_time_in_ms();
	ft_printf(philos, " is eating");
	usleep(philos->data->tteat);
	philos->nb_eat++;
}

void	ft_drop_fork(t_philo *ph)
{
	if (ph->id % 2 == 0)
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

void	ft_sleep(t_philo *philos)
{
	ft_printf(philos, "is sleeping");
	usleep(philos->data->ttsleep);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;
	long	time;

	ph = arg;
	if (ph->id % 2 == 1)
		usleep(400);
	while (1)
	{
		ft_take_fork(ph);
		ft_eat(ph);
		ft_drop_fork(ph);
		if (ph->data->ac == 6 && ph->nb_eat == ph->data->sixth_arg)
			return (arg);
		ft_sleep(ph);
		ft_printf(ph, "is thinking");
	}
	return (arg);
}

int	ft_init_thread(t_philo *philos, t_central *central)
{
	int	i;

	i = 0;
	while (i < central->nb_philos)
	{
		if (pthread_create
			(&philos[i].thread, NULL, ft_routine, &philos[i]) != 0)
			return (printf("Error create thread"), 1);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < central->nb_philos)
		{
			if (timeactuel - filo i last eat > ttdead)
			{
				ft_printf(&philos[i], "died");
				return (0);
			}
			i++;
		}
	}
	i = 0;
	while (i < central->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (printf("Error join"), 1);
		i++;
	}
	return (0);
}
