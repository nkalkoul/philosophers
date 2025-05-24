/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:04:09 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/24 16:12:01 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_parse_one(t_central *central)
{
	central->nb_philos = ft_atoi(central->av[1]);
	if (central->nb_philos == 0)
		return (printf("Error: nb philo more than 0\n"), 1);
	if (central->nb_philos < 0)
		return (1);
	central->ttdie = ft_atoi(central->av[2]);
	central->tteat = ft_atoi(central->av[3]);
	central->ttsleep = ft_atoi(central->av[4]);
	if (central->ac == 6)
		central->sixth_arg = ft_atoi(central->av[5]);
	else
		central->sixth_arg = 0;
	if (central->nb_philos < 0 || central->ttdie < 0 || central->tteat < 0
		|| central->ttsleep < 0 || central->sixth_arg < 0)
		return (1);
	return (0);
}

void	ft_init_data(t_central *central)
{
	central->ttdie *= 1000;
	central->tteat *= 1000;
	central->ttsleep *= 1000;
	central->died_or_alive = true;
	pthread_mutex_init(&central->is_died, NULL);
	pthread_mutex_init(&central->print, NULL);
}

int	ft_parsing(t_central *central)
{
	if (ft_parse_one(central) == 1)
		return (1);
	ft_init_data(central);
	return (0);
}

t_philo	*ft_init_table(t_central *central)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * central->nb_philos);
	if (!philos)
		return (NULL);
	while (i < central->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = central;
		philos[i].nb_eat = 0;
		pthread_mutex_init(&philos[i].l_fork, NULL);
		pthread_mutex_init(&philos[i].eat_last, NULL);
		pthread_mutex_init(&philos[i].have_eat, NULL);
		philos[i].r_fork = &philos[(i + 1) % central->nb_philos].l_fork;
		i++;
	}
	return (philos);
}
