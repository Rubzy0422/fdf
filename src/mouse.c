/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:34:50 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/07 01:27:34 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouseinit(t_mouse *mouse)
{
	mouse->x_new = 0;
	mouse->y_new = 0;
	mouse->x_old = 0;
	mouse->x_old = 0;
	return (0);
}

int		ft_mousemove(int x, int y, t_env *env)
{
	if (env->do_rot == 1)
	{
		env->mouse.x_new = (float)x;
		env->mouse.y_new = (float)y;
	
		env->rot.x += (env->mouse.x_new - env->mouse.x_old);
		env->rot.y += (env->mouse.y_new - env->mouse.y_old);
		ft_handelrotation(0, env);
		env->mouse.x_old = env->mouse.x_new;
		env->mouse.y_old = env->mouse.y_new;
	}
	return (0);
}

int		ft_mousetoggle(int key, t_env *env)
{
	if (key == MOUSETOG)
	{
		if (env->do_rot == 1)
			env->do_rot = 0;
		else
			env->do_rot = 1;
	}
	return (0);
}

int		ft_ctrl(int key, t_env *env)
{
	if (key == SPEEDINC)
		env->speed *= 2;
	if (key == SPEEDDEC)
		env->speed *= 0.5;
	return (0);
}
