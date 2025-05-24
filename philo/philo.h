/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:45:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/05/24 06:41:36 by nkalkoul         ###   ########.fr       */
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
	long			sixth_arg;
	bool			died_or_alive;
	pthread_mutex_t	is_died;
	pthread_mutex_t	print;
}					t_central;

typedef struct s_philos
{
	long			last_eat;
	int				id;
	int				nb_eat;
	pthread_t		thread;
	pthread_mutex_t	have_eat;
	pthread_mutex_t	eat_last;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_central		*data;
}					t_philo;

extern int	usleep(__useconds_t __useconds);
int			ft_parsing(t_central *central);
int			ft_atoi(char *s);
t_philo		*ft_init_table(t_central *central);
int			ft_init_thread(t_philo *philos, t_central *central);
long		ft_current_time(void);
int			ft_printf(t_philo *ph, char *msg, int monitor);
void		*ft_routine(void *arg);
int			ft_sleep(t_philo *philos);
void		ft_drop_fork(t_philo *ph);
int			ft_eat(t_philo *philos);
int			ft_take_fork(t_philo *ph);
int			ft_impair(t_philo *ph);
int			ft_pair(t_philo *ph);
int			ft_whenis_dead(t_philo *ph);
void		ft_end_mutex(t_philo *ph);
int			ft_usleep(t_philo *ph, long time);
void		*ft_routine1(void *arg);

#endif
