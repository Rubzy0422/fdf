/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:34:50 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/05 10:01:25 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mousemove(int x, int y, t_env *env)
{
	if (env->do_rot == 1)
	{
		env->rot.x = (double)x;
		env->rot.y = (double)y;
		ft_handelrotation(0, env);
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

int		ft_speed_ctrl(int key, t_env *env)
{
	if (key == SPEEDINC)
		env->speed *= 2;
	if (key == SPEEDDEC)
		env->speed *= 0.5;
	return (0);
}

int		ft_viewtoggle(int key, t_env *env)
{
	if (key == VIEWTOG)
	{
		if (env->project == 1)
			env->project = 0;
		else
			env->project = 1;
	}
	return (0);
}
