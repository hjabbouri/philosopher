/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:23:40 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/27 22:59:33 by hjabbour         ###   ########.fr       */
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
# define USE_MSG "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat].\n"
# define MALLOC_ERR "Memory allocation Error\n"
# define THREAD_CREAT_ERR "Thread creation Failed\n"

typedef struct  s_philo
{
    int             id_philo;
    pthread_t       thread;
    int             fork[2];
    time_t          last_meal;
    pthread_mutex_t mutex;
    int             state;
}   t_philo;

typedef struct  s_table
{
    int             num_philo;
    time_t          time_to_die;
    time_t          time_to_eat;
    time_t          time_to_sleep;
    int             nbr_philo_must_eat;
    int             *t_forks;
    t_philo         *philos;
}   t_table;


int     check_arguments(int ac);
int     parsing_argument(int ac, char **av, t_table *table);
t_table *init_table(int ac, char **av);
t_table *init_philo(int ac, char **av, t_table *t);
void    write_error(char *str);

#endif