/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:51:38 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/13 07:53:12 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*t;

	if (check_arguments(ac) == 0)
		return (EXIT_FAILURE);
	// t = parsing_argument(ac, av);
	t = init_table(ac, av);
	if (t == NULL)
		return (EXIT_FAILURE);
	return (on_free(t), EXIT_SUCCESS);
}
