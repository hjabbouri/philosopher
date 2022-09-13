/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:13:53 by hjabbour          #+#    #+#             */
/*   Updated: 2022/09/13 20:40:03 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_arguments(int ac)
{
	if (ac < 5 || ac > 6)
		return (write_error(USE_MSG), 0);
	return (1);
}

t_table	*parsing_argument(int ac, char **av)
{
	t_table	*t;

	t = init_table(ac, av);
	if (t == NULL)
		return (NULL);
	return (t);
}
