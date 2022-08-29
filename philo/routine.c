/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/29 22:11:25 by hjabbour         ###   ########.fr       */
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

static void is_eating(t_philo *p)
{
    // _forks();
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
    pthread_mutex_lock(&p->table->mut_print);
    usleep(500);
    print(p->table, p, "has taken a fork", p->fork_id[0]);
    print(p->table, p, "has taken a fork", p->fork_id[1]);
    print(p->table, p, "is eating", -1);
    while (get_time_now() - p->table->time_stamp < p->table->time_to_eat)
        continue ;
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
    pthread_mutex_unlock(&p->table->mut_print);
}

static void is_sleeping(t_philo *p)
{
    ;
}

static void is_thinking(t_philo *p)
{
    ;
}

void    *routine(void   *arg)
{
    t_philo *p;

    p = (t_philo *)arg;

    int i = 0;
    while (i < 1)
    {
        i++;
        is_eating(p);
        is_sleeping(p);
        is_thinking(p);
    }
    return 0;
}