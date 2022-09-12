/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:24:28 by hjabbour          #+#    #+#             */
/*   Updated: 2022/09/12 23:08:13 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_eating(t_philo *p)
{
    // if (p->table->death == 1)
    //     return ;
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
    if (get_time_now() - p->last_meal >= p->table->time_to_die)
        return 1;
        pthread_mutex_lock(&p->table->mut_print);
            print(p, "has taken a fork");
        pthread_mutex_unlock(&p->table->mut_print);
    if (p->table->num_philo == 1)
    {
        // usleep(p->table->time_to_die);//time to sleep
        ft_usleep(p->table->time_to_eat);// * 1000);/////////ft
        return 1;
    }
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
    if (get_time_now() - p->last_meal >= p->table->time_to_die)
        return 1;
        pthread_mutex_lock(&p->table->mut_print);
            print(p, "has taken a fork");
        pthread_mutex_unlock(&p->table->mut_print);
        pthread_mutex_lock(&p->table->mut_print);
        // pthread_mutex_lock(&p->mut_last_meal);
            p->last_meal = get_time_now();
        // pthread_mutex_unlock(&p->mut_last_meal);
            print(p, "is eating");
        pthread_mutex_unlock(&p->table->mut_print);
    // usleep(p->table->time_to_eat);// * 1000);/////////ft
    ft_usleep(p->table->time_to_eat);// * 1000);/////////ft
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
    if (p->nbr_eat > 0)
        p->nbr_eat--;
    return (0);
}

static void is_sleeping(t_philo *p)
{
    pthread_mutex_lock(&p->table->mut_print);
        print(p, "is sleping");
    pthread_mutex_unlock(&p->table->mut_print);
    // usleep(p->table->time_to_sleep);// * 1000);//ft_
    ft_usleep(p->table->time_to_sleep);// * 1000);//ft_
}

static void is_thinking(t_philo *p)
{
    pthread_mutex_lock(&p->table->mut_print);
        print(p, "is thinking");
    pthread_mutex_unlock(&p->table->mut_print);
}

void    *test_routine(void *arg)
{
    t_philo *p;

    p = (t_philo *)arg;
    // pthread_mutex_lock(&p->mut_last_meal);
        p->last_meal = get_time_now();
    // pthread_mutex_unlock(&p->mut_last_meal);
    // while (get_time_now() < p->table->start_time)
    //     continue ;
    while (*p->turn != p->id_philo % 2)
    ;
        // ft_usleep(t.tim)
        // is_thinking(p);
    while (p->nbr_eat == -2 || p->nbr_eat != 0)
    {
    printf("here %d\n", p->id_philo);
        if (is_eating(p) == 1)
            break ;
        is_sleeping(p);
        is_thinking(p);
        *p->turn = (p->id_philo + 1) % 2;
        // usleep(100 * 1000);
    }
    return (0);
}