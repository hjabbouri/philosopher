/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:57:33 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/26 21:28:59 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_data(int ac, char **av)
{
	t_philo	*data;

	data = malloc(sizeof(t_philo));
	if (data == NULL)
		throw_exit(NULL, false, MALLOC_ERR);
	data->num_philo = parssing_argument(av[1]);
	data->time_to_die = parssing_argument(av[2]);
	data->time_to_eat = parssing_argument(av[3]);
	data->time_to_sleep = parssing_argument(av[4]);
	data->nbr_philo_must_eat = -1;
	if (ac == 6)
		data->nbr_philo_must_eat = parssing_argument(av[5]);
	data->threads = malloc(sizeof(pthread_t) * data->num_philo);
	if (data->threads == NULL)
		throw_exit(&data, false, MALLOC_ERR);
	data->mutexes = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (data->mutexes == NULL)
		throw_exit(&data, false, MALLOC_ERR);
	data->philo_state[3] = (int){0};
	data->i = 0;
	init_threads(&data);
	init_mutexes(&data);
	return (&data);
	;
	;
}