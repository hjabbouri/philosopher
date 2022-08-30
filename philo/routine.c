/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/30 21:20:55 by hjabbour         ###   ########.fr       */
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

static int is_eating(t_philo *p)
{
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "has taken a fork");
    pthread_mutex_unlock(&p->table->mut_print);
    pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "has taken a fork");
    // pthread_mutex_unlock(&p->table->mut_print);
    // pthread_mutex_lock(&p->table->mut_print);
    print(p, "is eating");
    pthread_mutex_unlock(&p->table->mut_print);
    ft_usleep(p->table->time_to_eat);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
    pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
    return (0);
}

static int is_sleeping(t_philo *p)
{
    time_t  wake_up;

    wake_up = get_time_now() + p->table->time_to_sleep;
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "is sleeping");
    pthread_mutex_unlock(&p->table->mut_print);
    // ft_usleep(p->table->time_to_sleep);
    // (void)wake_up;
    while (get_time_now() < wake_up)
    {   
        // usleep(1000);///// more time if neccesry
        continue ;
    }
    return (0);
}

static int is_thinking(t_philo *p)
{
    pthread_mutex_lock(&p->table->mut_print);
    print(p, "is thinking");
    pthread_mutex_unlock(&p->table->mut_print);
    return (0);
}

void    *routine(void   *arg)
{
    t_philo *p;

    p = (t_philo *)arg;
    // int i = 0;
    // while (i < 1)
    // while (get_time_now() < p->table->start_time)
    //     continue ;
    if (p->id_philo % 2 != 0)
    {
        if (is_thinking(p) == -1)
            return 0;
    }
    // while (true)
    while (get_time_now() < p->table->start_time + 500)
    {
        // i++;
        if (is_eating(p) == -1)//NULL
            break ;
        if (is_sleeping(p) == -1)
            break ;
        if (is_thinking(p) == -1)
            break ;
    }
    return 0;
}

//c s x