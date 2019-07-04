/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:58:58 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/04 22:01:28 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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


int		ft_mousetoggle(int	key, t_env *env)
{
	if (key == 'm')
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
	if (key == 'i')
		env->speed *= 2;
	if (key == 'o')
		env->speed *= 0.5;
	return (0);
}

int		ft_scl_z(int key, t_env *env)
{
	if (key == 'k')
		env->scl_z *= 2;
	if (key == 'l')
		env->scl_z *= 0.5;
	return (0);
}
