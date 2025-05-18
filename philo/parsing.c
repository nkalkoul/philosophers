/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:04:09 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/17 04:01:19 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse_one(t_central *central)
{
	central->nb_philos = ft_atoi(central->av[1]);
	if (central->nb_philos == 0)
		return (printf("Error: nb philo more than 0"), 1);
	if (central->nb_philos < 0)
		return (1);
	central->ttdie = ft_atoi(central->av[2]);
	central->tteat = ft_atoi(central->av[3]);
	central->ttsleep = ft_atoi(central->av[4]);
	return (0);
}

int	ft_parsing(t_central *central)
{
	if (ft_parse_one(central == 1))
		return (1);
}
