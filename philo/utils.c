/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:16:24 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/30 21:08:30 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    write_error(char *str)
{
    int i;

    i = 0;
    while (str != NULL && str[i] != '\0')
    {
        write(2, &str[i], 1);
        i++;
    }
}

time_t  get_time_now(void)
{
    struct timeval  tv;
    
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    print(t_philo *p, char *str)
{
    // write();
    // should i get the time every time
    printf("%ld %d %s\n", get_time_now() - p->table->start_time, p->id_philo + 1, str);
    usleep(30 * 1000);
}

void    ft_usleep(time_t delai)
{
    time_t  now;
    time_t  end;

    now = get_time_now();
    end = get_time_now() + delai;
    while (now < end)
    {
        now = get_time_now();
    }
}