/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/09/01 17:11:32 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * eat 
 * sleep
 * think
 */

// static void _forks(int lf, int rf, char c)
// {
//     if (c == '1')
//     {
//         ;
//     }
//     else
//     {
//         ;
//     }
// }

static void is_sleeping(t_philo *p)
{
    time_t  wake_up;

    if (p->table->death == 1)
        return ;
    wake_up = get_time_now() + p->table->time_to_sleep;
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "is sleeping");
    pthread_mutex_unlock(&p->table->mut_print);
    while (get_time_now() < wake_up)
    {
        // usleep(1000);///// more time if neccesry
        continue ;
    }
}

static void is_eating(t_philo *p)
{
    if (p->table->death == 1)
        return ;
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "has taken a fork");
    pthread_mutex_unlock(&p->table->mut_print);
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "has taken a fork");
    pthread_mutex_unlock(&p->table->mut_print);
    pthread_mutex_lock(&p->table->mut_print);
    p->last_meal = get_time_now();
    print(p, "is eating");
    pthread_mutex_unlock(&p->table->mut_print);
    ft_usleep(p->table->time_to_eat);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
}

static void is_thinking(t_philo *p)
{
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "is thinking");
    pthread_mutex_unlock(&p->table->mut_print);
    //last meal time update
    printf("%ld | %ld\n", get_time_now(), p->last_meal);
    if (get_time_now() - p->last_meal <= p->table->time_to_eat)
    {
        // pthread_mutex_lock(&p->table->death_mutx);
        p->table->death = 1;
        // pthread_mutex_unlock(&p->table->death_mutx);
        pthread_mutex_lock(&p->table->mut_print);
        print(p, "died");
        pthread_mutex_unlock(&p->table->mut_print);
    }
}

void    *routine(void   *arg)
{
    t_philo *p;

    p = (t_philo *)arg;
    while (p->table->death != 1)//no one dies
    {
        // if (p->id_philo + p->increas % 2 == 0)// || p.bool == true)
        is_eating(p);
        is_sleeping(p);
        is_thinking(p);
    }
    return 0;
}

//c s x