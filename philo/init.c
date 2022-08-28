/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:57:33 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/28 22:45:44 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int mutex_init(t_table *t)
{
    int i;

    i = 0;
    // don t think i need it
    // while (i < t->num_philo - 1)
    // {
    //     if (pthread_mutex_init(t->philos[i].mutex, NULL) != 0)
    //         return (1);
    //     i++;
    // }
    while (i < t->num_philo)
    {
        if (pthread_mutex_init(&t->mut_forks[i], NULL) != 0)
            return (1);
        i++;
    }
    if (pthread_mutex_init(&t->mut_print, NULL) != 0)
        return (1);
    return (0);
}

static int thread_create(t_table *t)
{
    int i;

    i = 0;
    while (i < t->num_philo)
    {
        if (pthread_create(&t->philos[i].thread, NULL, &routine, &t->philos[i]) != 0)
            return (1);
        i++;
    }
    i = 0;
    while (i < t->num_philo)
    {
        pthread_join(t->philos[i].thread, NULL);
        i++;
    }
    return (mutex_init(t));
}

static t_table *init_philo(t_table *t)
{
    int     i;

    i = 0;
    while (i < t->num_philo)
    {
        t->philos[i].id_philo = i;
        t->philos[i].fork_id[0] = i - (i != 0);
        t->philos[i].fork_id[1] = i % t->num_philo;
        if (i % 2 != 0)
        {
            t->philos[i].fork_id[0] = (i + 1) % t->num_philo - 2;
            t->philos[i].fork_id[1] = i;
        }
        if (i == 0)
            t->philos[i].fork_id[1] = t->num_philo - 1;
        if (i == t->num_philo - 1)
            t->philos[i].fork_id[1] = t->num_philo - 1;
        t->philos[i].last_meal = 0;////////////////// time to modifie on strat simulation
        t->philos[i].state = 'n';//[0]
        i++;
    }
    if (thread_create(t) == 1)
        return (NULL);
    // mutex_init(t);
    // t->t_forks[i];
    // i = 0;
    // while (i < t->num_philo - 1)
    return (t);
}

static t_table *init_table(int ac, char **av)
{
    t_table *t;

    t = malloc(sizeof(t_table));
    if (t == NULL)
        return (write_error(MALLOC_ERR), NULL);
    t->num_philo = ft_atoi(av[1]);
    t->time_to_die = ft_atoi(av[2]);
    t->time_to_eat = ft_atoi(av[3]);
    t->time_to_sleep = ft_atoi(av[4]);
    t->nbr_philo_must_eat = -2;
    if (ac == 6)
        t->nbr_philo_must_eat = ft_atoi(av[5]);
    if (t->num_philo == -1 || t->time_to_die == -1 || \
            t->time_to_eat == -1 || t->time_to_sleep == -1 || \
            t->nbr_philo_must_eat == -1)
        return (write_error(ARG_ERR), NULL);
    t->mut_forks = malloc(sizeof(int) * t->num_philo);
    t->philos = malloc(sizeof(t_philo) * t->num_philo);
    if (t->mut_forks == NULL || t->philos == NULL)
        return (free(t->mut_forks), free(t->philos), write_error(MALLOC_ERR), NULL);
    ;
    t = init_philo(t);
    if (t == NULL)
        return (NULL);//freeeeeeeeeee
        /**
         * return (init_philo);
         * leaks ...
         */
    ;
    return (t);
}

t_table *parsing_argument(int ac, char **av)
{
    t_table *t;

    t = init_table(ac, av);
    if (t == NULL)
        return (NULL);
    // t = init_philo(t);
    // if (t == NULL)
    //     return (NULL);
    return (t);
}