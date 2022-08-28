/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjabbour <hjabbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:00:20 by hjabbour          #+#    #+#             */
/*   Updated: 2022/08/28 22:57:55 by hjabbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *id)//void **p)//t_philo *p)
{
    // pthread_mutex_lock()
    printf("hello from thread routine philo id: %d\n", *(int *)id);//p->id_philo);
    ;
    return 0;
}