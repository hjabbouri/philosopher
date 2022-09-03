/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:57:33 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/31 12:42:34by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int mutex_init(t_table *t)
{
    int i;

    i = 0;
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

    if (mutex_init(t) == 1)
        return (1);
    i = 0;
    while (i < t->num_philo)
    {
        // if (pthread_create(&(t->philos[i].thread), NULL, &routine, &(t->philos[i])) != 0)
        if (pthread_create(&(t->philos[i].thread), NULL, &test_routine, &(t->philos[i])) != 0)
            return (1);
        i++;
    }
    i = 0;
    while (i < t->num_philo)
    {
        // pthread_join(t->philos[i].thread, NULL);
        pthread_detach(t->philos[i].thread);
        i++;
    }
    ;
    usleep(100 * 1000);
    // while (get_time_now() < t->start_time)
    //     continue ;
    i = 0;
    while (true)
    {
        // if (t->death == 1)
        //     break ;
        if ((get_time_now() - t->philos[i].last_meal > t->time_to_die))// && (t->philos[i].nbr_eat == -2 || t->philos[i].nbr_eat != 0))// && t->death != 1)
        {
            pthread_mutex_lock(&t->mut_print);
            print(&t->philos[i], "died");
            // return (0);
            break ;
        }
        ;
        i = (i + 1) % t->num_philo;
    }
    ;
    return (0);
}

//full
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
        if (i == 0 || i == t->num_philo - 1)
            t->philos[i].fork_id[(i == 0)] = t->num_philo - 1 - (i != 0);
        t->philos[i].last_meal = 0;////////////////// time to modifie on strat simulation
        t->philos[i].nbr_eat = t->nbr_philo_must_eat;//0;///////
        t->philos[i].table = t;
        i++;
    }
    if (thread_create(t) == 1)
        return (NULL);
    return (t);
}

//full
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
    t->start_time = get_time_now();
    t->nbr_philo_must_eat = -2;
    t->death = 0;////////////
    if (ac == 6)
        t->nbr_philo_must_eat = ft_atoi(av[5]);
    if (t->num_philo == -1 || t->time_to_die == -1 || \
            t->time_to_eat == -1 || t->time_to_sleep == -1 || \
            t->nbr_philo_must_eat == -1)
        return (write_error(ARG_ERR), NULL);
    t->mut_forks = malloc(sizeof(pthread_mutex_t) * t->num_philo);
    t->philos = malloc(sizeof(t_philo) * t->num_philo);
    if (t->mut_forks == NULL || t->philos == NULL)
        return (free(t->mut_forks), free(t->philos), write_error(MALLOC_ERR), NULL);
    t = init_philo(t);/////////return init_philo
    if (t == NULL)//////////
        return (NULL);//////////
    return (t);
}

t_table *parsing_argument(int ac, char **av)
{
    t_table *t;

    t = init_table(ac, av);
    if (t == NULL)
        return (NULL);
    return (t);
}