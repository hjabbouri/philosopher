/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/15 22:00:42 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdbool.h>

static int	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
	if (get_time_now() - p->last_meal > p->table->time_to_die)
		return (1);
	print(p, "has taken a fork");
	if (p->table->num_philo == 1)
		return (ft_usleep(p->table->time_to_eat), 1);
	pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
	if (get_time_now() - p->last_meal > p->table->time_to_die)
		return (1);
	print(p, "has taken a fork");
	print(p, "is eating");
	pthread_mutex_lock(&p->table->mut_last_meal);
	p->last_meal = get_time_now();
	pthread_mutex_unlock(&p->table->mut_last_meal);
	ft_usleep(p->table->time_to_eat);
	if (p->nbr_eat > 0)
		p->nbr_eat--;
	pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
	pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
	return (0);
}

static void	is_sleeping(t_philo *p)
{
	print(p, "is sleping");
	ft_usleep(p->table->time_to_sleep);
}

static void	is_thinking(t_philo *p)
{
	print(p, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(&p->table->mut_last_meal);
	p->last_meal = get_time_now();
	pthread_mutex_unlock(&p->table->mut_last_meal);
	while (true)
	{
		if (is_eating(p) == 1)
			break ;
		if (p->nbr_eat == 0)
		{
			pthread_mutex_lock(&p->table->mut_eating);
			p->table->eating++;
			pthread_mutex_unlock(&p->table->mut_eating);
		}
		is_sleeping(p);
		is_thinking(p);
	}
	return (0);
}
