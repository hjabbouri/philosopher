/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:51:38 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/27 18:45:52by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//id -> philo[(id + 1) % N]
/*
 *  parsing argument
 */
int main(int ac, char **av)
{
    t_table *t;
    // t_philo *p;

    if (check_arguments(ac) == 0)
        return (EXIT_FAILURE);
    t = init_table(ac,av);
    if (t == NULL)
        return (EXIT_FAILURE);
    // p = init_philo(ac, av, t);
    // if (p == NULL)
    //     return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}