/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:45:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/17 03:09:00 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_central
{
	char			**av;
	int				ac;
	long long		st_time;
	int				nb_philos;
	long			ttdie;
	long			tteat;
	long			ttsleep;
	long			nb_eat;
	long			sixth_arg;
	bool			died_or_alive;
	pthread_mutex_t	is_died;
	pthread_mutex_t	print;
}					t_central;

typedef struct s_philos
{
	int				id;
	int				nb_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_central		*data;
}					t_philo;

int		ft_parsing(t_central *central);
long	ft_atoi(char *s);

#endif
