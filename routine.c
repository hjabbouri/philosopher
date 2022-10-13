/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/13 09:28:46 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->table->mut_forks[p->fork_id[0]]);
	if (get_time_now() - p->last_meal > p->table->time_to_die)
		return (1);
	pthread_mutex_lock(&p->table->mut_print);
	print(p, "has taken a fork");
	pthread_mutex_unlock(&p->table->mut_print);
	if (p->table->num_philo == 1)
		return (ft_usleep(p->table->time_to_eat), 1);
	pthread_mutex_lock(&p->table->mut_forks[p->fork_id[1]]);
	if (get_time_now() - p->last_meal > p->table->time_to_die)
		return (1);
	pthread_mutex_lock(&p->table->mut_print);
	print(p, "has taken a fork");
	pthread_mutex_unlock(&p->table->mut_print);
	pthread_mutex_lock(&p->table->mut_print);
	print(p, "is eating");
	pthread_mutex_unlock(&p->table->mut_print);
	p->last_meal = get_time_now();
	ft_usleep(p->table->time_to_eat);
	pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[0]]);
	pthread_mutex_unlock(&p->table->mut_forks[p->fork_id[1]]);
	if (p->nbr_eat > 0)
		p->nbr_eat--;
	return (0);
}

static void	is_sleeping(t_philo *p)
{
	pthread_mutex_lock(&p->table->mut_print);
	print(p, "is sleping");
	pthread_mutex_unlock(&p->table->mut_print);
	ft_usleep(p->table->time_to_sleep);
}

static void	is_thinking(t_philo *p)
{
	pthread_mutex_lock(&p->table->mut_print);
	print(p, "is thinking");
	pthread_mutex_unlock(&p->table->mut_print);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->last_meal = get_time_now();
	// while (p->nbr_eat == -2 || p->nbr_eat != 0)
	while (true)
	{
		if (is_eating(p) == 1)
			break ;
		// if (p->nbr_eat == 0)
		// 	break ;
		if (p->nbr_eat == 0)
		{
			pthread_mutex_lock(p->table->mut_eating);
			p->table->eating++;
			pthread_mutex_unlock(p->table->mut_eating);
			// break ;
		}
		is_sleeping(p);
		is_thinking(p);
	}
	return (0);
}
