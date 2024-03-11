/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:57:33 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/15 21:58:40 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_t.h>
#include <time.h>

static int	mutex_init(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_philo)
	{
		if (pthread_mutex_init(&t->mut_forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&t->mut_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&t->mut_eating, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&t->mut_last_meal, NULL) != 0)
		return (1);
	return (0);
}

static void	main_thread(t_table *t)
{
	int		i;
	time_t	time;

	i = 0;
	while (true)
	{
		pthread_mutex_lock(&t->mut_last_meal);
		time = get_time_now() - t->philos[i].last_meal;
		pthread_mutex_unlock(&t->mut_last_meal);
		if (time > t->time_to_die)
		{
			pthread_mutex_lock(&t->mut_print);
			printf("%ld %d died\n", (get_time_now() - t->start_time), \
				t->philos[i].id_philo + 1);
			break ;
		}
		if (t->eating == t->num_philo)
		{
			pthread_mutex_lock(&t->mut_print);
			break ;
		}
		i = (i + 1) % t->num_philo;
		usleep(500);
	}
	usleep(200 * 1000);
}

static int	thread_create(t_table *t)
{
	int	i;

	if (mutex_init(t) == 1)
		return (1);
	i = 0;
	t->start_time = get_time_now();
	while (i < t->num_philo)
	{
		if (pthread_create(&(t->philos[i].thread), NULL, &routine, \
			&(t->philos[i])) != 0)
			return (1);
		usleep(500);
		i++;
	}
	i = 0;
	while (i < t->num_philo)
	{
		pthread_detach(t->philos[i].thread);
		i++;
	}
	main_thread(t);
	return (0);
}

static t_table	*init_philo(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_philo)
	{
		t->philos[i].id_philo = i;
		t->philos[i].fork_id[0] = i - (i != 0);
		t->philos[i].fork_id[1] = i % t->num_philo;
		if (i % 2 != 0)
		{
			t->philos[i].fork_id[0] = (i + 1) % t->num_philo - 2;
			t->philos[i].fork_id[1] = i;
		}
		if (i == 0 || i == t->num_philo - 1)
			t->philos[i].fork_id[(i == 0)] = t->num_philo - 1 - (i != 0);
		t->philos[i].last_meal = 0;
		t->philos[i].nbr_eat = t->must_eat;
		t->philos[i].table = t;
		i++;
	}
	if (thread_create(t) == 1)
		return (NULL);
	return (t);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*t;

	t = malloc(sizeof(t_table));
	if (t == NULL)
		return (on_error(ALOC_ERR), NULL);
	t->num_philo = ft_atoi(av[1]);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep = ft_atoi(av[4]);
	t->must_eat = -2;
	if (ac == 6)
		t->must_eat = ft_atoi(av[5]);
	if (t->num_philo == -1 || t->time_to_die == -1 || \
			t->time_to_eat == -1 || t->time_to_sleep == -1 || t->must_eat == -1)
		return (on_error(ARG_ERR), free(t), NULL);
	t->mut_forks = malloc(sizeof(pthread_mutex_t) * t->num_philo);
	t->philos = malloc(sizeof(t_philo) * t->num_philo);
	if (t->mut_forks == NULL || t->philos == NULL)
		return (free(t->mut_forks), free(t->philos), on_error(ALOC_ERR), NULL);
	t->eating = 0;
	t = init_philo(t);
	if (t == NULL)
		return (free(t->mut_forks), free(t->philos), NULL);
	return (t);
}
