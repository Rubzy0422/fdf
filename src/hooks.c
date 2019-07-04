/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:56:35 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/04 17:13:10 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	    ft_handelhooks(t_env *env)
{
    mlx_hook(env->win, 2, 1L << 0, ft_handelkey, env);
    mlx_hook(env->win, 17, 0, fdf_exit, env);
}

int	    fdf_exit(void *param)
{
	t_env   *env;

	env = (t_env *)param;
	if (env->model)
    	ft_delete_map(env->model, env);
	if (env->img.w > 0)
		mlx_destroy_image(env->mlx, env->img.ptr_img);
    if (env->mlx)
    	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

int	    ft_handelkey(int key, void *param)
{
    t_env   *env;

	env = (t_env *)param;
	if (key == ESC)
		fdf_exit(env);
	if (key == W)
		env->loc.y -= (1 / (SPEED * env->zoom));
	if (key == S)
		env->loc.y += (1 / (SPEED * env->zoom));
	if (key == A)
		env->loc.x -= (1 /(SPEED * env->zoom));
	if (key == D)
		env->loc.x += (1 /(SPEED * env->zoom));
	if (key == ARROWUP)
		env->zoom *= 2;
	if (key == ARROWDOWN)
		env->zoom *= 0.5; 
	ft_handelrotation(key, env);
	return (0);
}

int		ft_handelrotation(int key, t_env *env)
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
		env->rot.x = 45;
		env->rot.y = 45;
		env->rot.z = 45;
		env->zoom = ft_zoom_hndl(env->sz.y,env->sz.x);
	}
	ft_create_view(env);	
	return (0);
}

double	ft_zoom_hndl(unsigned int y, unsigned int x)
{
	y = 0;
	x = 0;
	//(env->sz.x + env->sz.z / 2)
	return (0.1);
}
