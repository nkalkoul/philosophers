/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:43:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/27 08:57:50 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = arg;
	if (ph->id % 2 == 1)
		usleep(100);
	while (1)
	{
		if (ft_take_fork(ph) == 1)
			return (arg);
		if (ft_eat(ph) == 1)
			return (arg);
		ft_drop_fork(ph);
		pthread_mutex_lock(&ph->have_eat);
		if (ph->data->ac == 6 && ph->nb_eat == ph->data->sixth_arg)
		{
			pthread_mutex_unlock(&ph->have_eat);
			return (arg);
		}
		pthread_mutex_unlock(&ph->have_eat);
		if (ft_sleep(ph) == 1)
			return (arg);
		if (ft_printf(ph, "is thinking", 0) == 1)
			return (arg);
	}
	return (arg);
}

long	ft_ifeat(t_philo *ph)
{
	long	val;

	pthread_mutex_lock(&ph->eat_last);
	val = ph->last_eat;
	pthread_mutex_unlock(&ph->eat_last);
	return (val);
}

int	ft_monitoring_dead(t_philo *philos, t_central *central, int *i)
{
	if (*i == -1)
		*i = central->nb_philos - 1;
	if (ft_current_time() - ft_ifeat(&philos[*i]) >= central->ttdie / 1000)
	{
		pthread_mutex_lock(&philos->data->is_died);
		central->died_or_alive = DEAD;
		pthread_mutex_unlock(&philos->data->is_died);
		ft_printf(&philos[*i], "died", 1);
		return (1);
	}
	return (0);
}

void	ft_monitoring(t_philo *philos, t_central *central)
{
	int	i;
	int	nb_eat;
	int	j;

	i = central->nb_philos - 1;
	j = central->nb_philos / 3;
	nb_eat = 0;
	while (1)
	{
		if (ft_monitoring_dead(philos, central, &i) == 1)
			break ;
		if (ft_monitoring_dead(philos, central, &j) == 1)
			break ;
		pthread_mutex_lock(&philos[i].have_eat);
		if (central->ac == 6 && philos[i].nb_eat == central->sixth_arg)
		{
			nb_eat++;
			if (nb_eat == philos->data->nb_philos)
			{
				pthread_mutex_unlock(&philos[i].have_eat);
				break ;
			}
		}
		pthread_mutex_unlock(&philos[i].have_eat);
		i--;
		j--;
	}
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
	ft_monitoring(philos, central);
	i = 0;
	while (i < central->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (printf("Error join"), 1);
		i++;
	}
	return (0);
}
