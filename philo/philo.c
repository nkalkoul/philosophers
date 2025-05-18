/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:47:55 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/17 00:33:19 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*fait le parsing et remplir les int de la struct central*/
int main(int ac, char **av)
{
	t_central		central;
	t_philo			*philos;

	if (ac < 5 || ac > 6)
		return (EXIT_FAILURE);
	central.ac = ac;
	central.av = av;
	if (ft_parsing(&central, av) == 1)
		return (EXIT_FAILURE);
	if (/*lance les thread et init les phtread_mutex fork*/)
		return (EXIT_FAILURE);

}