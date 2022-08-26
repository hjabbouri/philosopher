/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:23:40 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/26 21:33:20 by hjabbour         ###   ########.fr       */
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
# define MIN_INT -2147483648
# define ARG_ERR "Invalid Argument Number.\n"
# define USE_MSG "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat].\n"
# define MALLOC_ERR "Memory allocation Error\n"
# define THREAD_CREAT_ERR "Thread creation Failed\n"
# define THREAD_JOIN_ERR "Thread joining Failed\n"
# define MUTEX_INIT_ERR "Mutex init Failed\n"
# define MUTEX_DESTROY_ERR "Mutex destroy Failed\n"

typedef struct  s_table {
    t_philo *philo;
    unsigned int    num_philo;
    time_t          time_to_die;
    time_t          time_to_eat;
    time_t          time_to_sleep;
    int             nbr_philo_must_eat;
}   t_table;

typedef struct  s_philo {
    int             philo_id;
    pthread_t       *threads;
    pthread_mutex_t *mutexes;
    int             philo_state[3];
    int             i;
} t_philo;

// typedef struct s_philo {
//     unsigned int    num_philo;
//     time_t          time_to_die;
//     time_t          time_to_eat;
//     time_t          time_to_sleep;
//     int             nbr_philo_must_eat;
//     pthread_t       *threads;
//     pthread_mutex_t *mutexes;
//     int             philo_state[3];
//     int             i;
// } t_philo;

void	check_argument(int ac, char **av);
void    throw_error(char *s1, char *s2);
void    write_error(char *str);
void    throw_exit(t_philo *d, bool yesno, char *s);
t_philo	*init_data(int ac, char **av);
int     parssing_argument(char *av);
void	init_threads(t_philo *data);
void	init_mutexes(t_philo *data);
void    destroy_mutexes(t_philo *data);
void	*routine();

#endif