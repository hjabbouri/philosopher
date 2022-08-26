/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:59:01 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/26 12:34:17 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_philo *data)
{
	data->i = 0;
	while (data->i < data->num_philo - 1)
	{
		if (pthread_mutex_init(data->mutexes + data->i, NULL) != 0)
			throw_exit(data, true, MUTEX_INIT_ERR);
		data->i++;
	}
}

void    destroy_mutexes(t_philo *data)
{
    data->i = 0;
    while (data->i < data->num_philo - 1)
    {
        if (pthread_mutex_destroy(data->mutexes + data->i) != 0)
            throw_exit(data, true, MUTEX_DESTROY_ERR);
        data->i++;
    }
}