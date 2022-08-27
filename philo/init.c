/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:57:33 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/27 23:06:49 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table *init_philo(int ac, char **av, t_table *t)
{
    int     i;

    i = 0;
    while (i < t->num_philo - 1)
    {
        t->philos[i].id_philo = i;
        t->philos[i].thread = ;
        i++;
    }
    return (t);
}

t_table *init_table(int ac, char **av)
{
    t_table *t;

    t = malloc(sizeof(t_table));
    if (t == NULL)
        return (write_error(MALLOC_ERR), NULL);
    if (parsing_argument(ac, av, t) == -1)
        return (free(t), NULL);
    t = init_philo(ac, av, t);
    return (t);
}