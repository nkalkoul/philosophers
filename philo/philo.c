/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:47:55 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/24 07:18:16 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_time(t_philo *ph, t_central *central)
{
	int	i;

	i = 0;
	central->start_time = ft_current_time();
	while (i < central->nb_philos)
	{
		ph[i].last_eat = central->start_time;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_central		central;
	t_philo			*philos;

	if (ac < 5 || ac > 6)
		return (1);
	central.ac = ac;
	central.av = av;
	if (ft_parsing(&central) == 1)
		return (1);
	philos = ft_init_table(&central);
	if (!philos)
		return (1);
	if (central.nb_philos == 1)
	{
		if (pthread_create
			(&philos[0].thread, NULL, ft_routine1, &philos[0]) != 0)
			return (printf("Error create thread"), 1);
	}
	else
	{
		ft_set_time(philos, &central);
		if (ft_init_thread(philos, &central) == 1)
			return (1);
	}
	ft_end_mutex(philos);
	return (0);
}
