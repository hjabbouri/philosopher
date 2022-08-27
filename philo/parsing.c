/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:13:53 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/27 22:28:20 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * work propely with god norm
 * */
int	ft_atoi(char *av)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (av[i] == ' ')
		i++;
	if (av[i] == '+')
		i++;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
			nbr = nbr * 10 + av[i] - '0';
		else
			return (-1);
		if (nbr > MAX_INT)
			return (-1);
		i++;
	}
	if (i == 0 || nbr > MAX_INT || nbr == 0)
		return (-1);
	return ((int)nbr);
}

int parsing_argument(int ac, char **av, t_table *t)
{
    t->num_philo = ft_atoi(av[1]);
    t->time_to_die = ft_atoi(av[2]);
    t->time_to_eat = ft_atoi(av[3]);
    t->time_to_sleep = ft_atoi(av[4]);
    t->nbr_philo_must_eat = -2;
    if (ac == 6)
        t->nbr_philo_must_eat = ft_atoi(av[5]);
    if (t->num_philo == -1 || t->time_to_die == -1 || \
            t->time_to_eat == -1 || t->time_to_sleep == -1 || \
            t->nbr_philo_must_eat == -1)
        return (write_error(ARG_ERR), -1);
    t->t_forks = malloc(sizeof(int) * t->num_philo);
    t->philos = malloc(sizeof(t_philo) * t->num_philo);
    if (t->t_forks == NULL || t->philos == NULL)
        return (free(t->t_forks), free(t->philos), write_error(MALLOC_ERR), -1);
    ;
    return (1);
}

int check_arguments(int ac)
{
    if (ac < 5 || ac > 6)
        return (write_error(USE_MSG), 0);
    return (1);
}
