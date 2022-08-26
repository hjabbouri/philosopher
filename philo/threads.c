/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:27:02 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/25 21:01:27 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_philo *data)
{
	data->i = 0;
	while (data->i < data->num_philo - 1)
	{
		if (pthread_create(data->threads + data->i, NULL, &routine, NULL) != 0)
			throw_exit(data, NULL);
		data->i++;
	}
	data->i = 0;
	while (data->i < data->num_philo - 1)
	{
		pthread_join(data->threads + data->i, NULL);
		data->i++;
	}
}