/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:45:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/22 03:51:18 by nkalkoul         ###   ########.fr       */
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

# define DEAD false
# define ALIVE true

typedef struct s_central
{
	char			**av;
	int				ac;
	long			start_time;
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
	int				last_eat;
	int				id;
	int				nb_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_central		*data;
}					t_philo;

extern int	usleep(__useconds_t __useconds);
int			ft_parsing(t_central *central);
int			ft_atoi(char *s);
t_philo		*ft_init_table(t_central *central);
int			ft_init_thread(t_philo *philos, t_central *central);
long		ft_current_time_in_ms(void);
void		ft_printf(t_philo *ph, char *msg);

#endif
