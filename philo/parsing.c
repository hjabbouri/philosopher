/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:13:53 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/26 13:30:38 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parssing_argument(char *av)
{
    long    nbr;
    int     i;
    
    i = 0;
    nbr = 0;
    if (av == NULL)
        throw_exit(NULL, false, ARG_ERR);
    while (av[i] != '\0')
    {
        while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
            i++;
        if (av[i] >= 48 && av[i] >= 57)
            nbr = (nbr * 10) + (av[i] - 48);
        else
            throw_exit(NULL, false, ARG_ERR);
        i++;
    }
    if (nbr > MAX_INT || nbr <= 0)
        throw_exit(NULL, false, ARG_ERR);
    return ((int)nbr);
}

void	check_argument(int ac, char **av)
{
    if (ac < 5)
        throw_error(ARG_ERR, USE_MSG);
    else if (ac != 5 || ac != 6)
        throw_error(ARG_ERR, NULL);
    else
        throw_error(ARG_ERR, NULL);
}
