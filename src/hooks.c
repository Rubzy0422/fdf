/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:29:15 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/06 09:26:09 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_handelhooks(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, ft_handelkey, env);
	mlx_hook(env->win, 17, 0, fdf_exit, env);
	mlx_hook(env->win, 6, 1L << 6, ft_mousemove, env);
}

int			fdf_exit(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->model)
		ft_delete_map(env->model, env);
	if (env->img.w > 0)
		mlx_destroy_image(env->mlx, env->img.ptr_img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

int			ft_handelkey(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == ESC)
		fdf_exit(env);
	if (key == W)
		env->loc.y -= (1 / (env->speed * env->zoom));
	if (key == S)
		env->loc.y += (1 / (env->speed * env->zoom));
	if (key == A)
		env->loc.x -= (1 / (env->speed * env->zoom));
	if (key == D)
		env->loc.x += (1 / (env->speed * env->zoom));
	if (key == ARROWUP)
		env->zoom *= 2;
	if (key == ARROWDOWN)
		env->zoom *= 0.5;
	ft_handelrotation(key, env);
	ft_mousetoggle(key, env);
	ft_ctrl(key, env);
	return (0);
}

int			ft_handelrotation(int key, t_env *env)
{
	if (key == NUMUP)
		env->rot.x += env->speed;
	if (key == NUMDOWN)
		env->rot.x -= env->speed;
	if (key == NUMLEFT)
		env->rot.y += env->speed;
	if (key == NUMRIGHT)
		env->rot.y -= env->speed;
	if (key == NUM_7)
		env->rot.z += env->speed;
	if (key == NUM_9)
		env->rot.z -= env->speed;
	if (key == NUM_5)
	{
		env->loc.x = 0;
		env->loc.y = 0;
		env->rot.x = 275;
		env->rot.y = 90;
		env->rot.z = 45;
		env->zoom = ft_zoom_hndl(env->sz.y, env->sz.x);
		env->speed = 2;
	}
	ft_create_view(env);
	return (0);
}

double		ft_zoom_hndl(unsigned int y, unsigned int x)
{
	double side;
	double diag;
	double ratio;

	side = 0;
	if (y > x)
		side = y;
	else
		side = x;

	diag = sqrt((pow(x , 2) + pow( y , 2)));
	ratio = ((double)side / diag);
	return((side / (diag / (ratio / (side/2)))));
}
