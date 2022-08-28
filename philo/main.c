/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:51:38 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/28 21:03:25 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//id -> philo[(id + 1) % N]
/*
 *  parsing argument
 */

static void on_free(t_table *t)
{
    int i;

    i = 0;
    while (i < t->num_philo)
    {
        if (pthread_mutex_destroy(&t->mut_forks[i]) != 0)
            break ;
        i++;
    }
    pthread_mutex_destroy(&t->mut_print);//error case
    free(t->philos);
    free(t->mut_forks);
    free(t);
    // mutex destroy
}

int main(int ac, char **av)
{
    t_table *t;

    if (check_arguments(ac) == 0)
        return (EXIT_FAILURE);
    t = parsing_argument(ac, av);
    if (t == NULL)
        return (EXIT_FAILURE);//maybe cause some error but ifmit s NULL then no problem at all
        // return (on_free(t), EXIT_FAILURE);//maybe cause some error but ifmit s NULL then no problem at all
    return (on_free(t), EXIT_SUCCESS);
}