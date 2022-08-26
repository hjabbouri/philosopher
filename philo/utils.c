/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:16:24 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/25 22:48:12 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    write_error(char *str)
{
    int i;

    i = 0;
    while (str != NULL && str[i] != '\0')
    {
        write(2, &str[i], 1);
        i++;
    }
}

void    throw_error(char *s1, char *s2)
{
    if (s1 != NULL)
        write_error(s1);
    if (s2 != NULL)
        write_error(s2);
    exit(EXIT_FAILURE);
}

void    throw_exit(t_philo *d, bool yesno, char *s)
{
    if (s != NULL)
        write_error(s);
    if (d->threads != NULL)
        free(d->threads);
    if (d->mutexes != NULL)
        free(d->mutexes);
    if (yesno == true)
        destroy_mutexes(d);
    exit(EXIT_FAILURE);
}