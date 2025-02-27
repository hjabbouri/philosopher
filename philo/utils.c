/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:16:24 by hjabbour          #+#    #+#             */
/*   Updated: 2022/10/15 21:59:44 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	on_error(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

time_t	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->table->mut_print);
	printf("%ld %d %s\n", (get_time_now() - p->table->start_time), \
			p->id_philo + 1, str);
	pthread_mutex_unlock(&p->table->mut_print);
}

void	ft_usleep(time_t delai)
{
	time_t	end;

	end = get_time_now() + delai;
	while (get_time_now() < end)
	{
		usleep(500);
	}
}

void	on_free(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->num_philo)
	{
		if (pthread_mutex_destroy(&t->mut_forks[i]) != 0)
			break ;
		i++;
	}
	pthread_mutex_destroy(&t->mut_print);
	pthread_mutex_destroy(&t->mut_eating);
	pthread_mutex_destroy(&t->mut_last_meal);
	free(t->philos);
	free(t->mut_forks);
	free(t);
}
