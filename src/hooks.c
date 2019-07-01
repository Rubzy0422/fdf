/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:56:35 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 20:07:48 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	    ft_handelhooks(t_env *env)
{
    mlx_hook(env->win, 2, 0, ft_handelkey, env);
    mx_hook(env->win, 17, 0, fdf_exit, env);
}

int	    fdf_exit(void *param)
{
    t_env   *env;
    env = (t_env *)param;
    exit(0);
    return (0);
}

int	    ft_handelkey(int key, void *param)
{
    t_env   *env;
    env = (t_env *)param;
    if (key == ESC)
    	fdf_exit(param);
    if (key == W)
    if (key == S)
    if (key == A)
    if (key == D)
    if (key == ARROWUP)
    if (key == ARROWDOWN)
    ft_handelrotation(key, env);
    return (0);
}

int	    ft_handelrotation(int key, t_env *env)
{
    if (key == NUMUP)
    if (key == NUMDOWN)
    if (key == NUMLEFT)
    if (key == NUMRIGHT)
    if (key == NUM_7)
    if (key == NUM_9)
    if (key == NUM_5)
    //APPLY LOC ROT CHANGES TO DISPLAY
    return (0);
}
