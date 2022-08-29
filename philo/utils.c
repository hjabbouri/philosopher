/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:16:24 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/29 21:08:35 by hjabbour         ###   ########.fr       */
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

void    print(t_table *t, t_philo *p, char *str, int id)
{
    // write();
    // lock the print
    // should i get the time every time
    // pthread_mutex_lock(&t->mut_print);
    printf("%ld %d %s %d\n", get_time_now() - t->time_stamp, p->id_philo + 1, str, id);
    // pthread_mutex_unlock(&t->mut_print);
}