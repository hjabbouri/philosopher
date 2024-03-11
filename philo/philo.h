/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:23:40 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/15 21:46:09 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647
# define ARG_ERR "Invalid Argument.\n"
# define USE_MSG "./philo \"philo nbr\" \"time to die\" \
\"time to eat\" \"time to sleep\" [must eat nbr].\n"
# define ALOC_ERR "Memory allocation Error\n"
# define THREAD_CREAT_ERR "Thread creation Failed\n"

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id_philo;
	pthread_t		thread;
	int				fork_id[2];
	time_t			last_meal;
	int				nbr_eat;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				num_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	int				must_eat;
	pthread_mutex_t	*mut_forks;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_eating;
	pthread_mutex_t	mut_last_meal;
	int				eating;
	t_philo			*philos;
}	t_table;

int		check_arguments(int ac);
t_table	*init_table(int ac, char **av);
void	on_error(char *str);
int		ft_atoi(char *av);
void	*routine(void *arg);
time_t	get_time_now(void);
void	print(t_philo *p, char *str);
void	ft_usleep(time_t delai);
void	on_free(t_table *t);

#endif
