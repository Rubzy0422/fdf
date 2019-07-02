/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:56:35 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/02 20:25:33 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	    ft_handelhooks(t_env *env)
{
    mlx_hook(env->win, 2, 0, ft_handelkey, env);
    mlx_hook(env->win, 17, 0, fdf_exit, env);
}

int	    fdf_exit(void *param)
{
    t_env   *env;

	env = (t_env *)param;
    ft_delete_map(env->model, env);
	mlx_destroy_window(env->mlx, env->win);
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
	env->loc.y += SPEED;
    if (key == S)
	env->loc.y -= SPEED;
    if (key == A)
		env->loc.x += SPEED;
    if (key == D)
		env->loc.x -= SPEED;
    if (key == ARROWUP)
		env->zoom *= 2;
    if (key == ARROWDOWN)
		env->zoom *= 0.5; 
    ft_handelrotation(key, env);
    return (0);
}

int	    ft_handelrotation(int key, t_env *env)
{
    if (key == NUMUP)
    	env->rot.x += SPEED;
    if (key == NUMDOWN)
    	env->rot.x -= SPEED;
    if (key == NUMLEFT)
    	env->rot.y += SPEED;
    if (key == NUMRIGHT)
    	env->rot.y -= SPEED; 
    if (key == NUM_7)
		env->rot.z += SPEED;
    if (key == NUM_9)
		env->rot.z -= SPEED;
    if (key == NUM_5)
	{
		env->loc.x = 0;
		env->loc.y = 0;
		env->rot.x = -95;
		env->rot.y = 90;
		env->rot.z = -90;
		env->zoom = 1;
	}
	ft_create_view(env);	
    return (0);
}
