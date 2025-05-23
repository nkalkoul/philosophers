/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:47:55 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/23 08:59:39 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (ft_init_thread(philos, &central) == 1)
		return (1);
	ft_end_mutex(philos);
	free(philos);
	return (0);
}
