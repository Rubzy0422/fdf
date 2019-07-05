/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:19 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/05 09:45:42 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_fromndc(t_cord *src, t_cord *dest)
{
	dest->x = src->x * 0.5 * WIN_X;
	dest->y = src->y * 0.5 * WIN_Y;
	dest->x += (0.5 * WIN_X);
	dest->y += (0.5 * WIN_Y);
}

void				ft_delete_map(t_cord **map, t_env *env)
{
	unsigned int	yc;

	yc = 0;
	while (yc < env->sz.y)
	{
		free(map[yc]);
		yc++;
	}
	free(map);
}

void				ft_create_view(t_env *env)
{
	unsigned int	yc;

	yc = 0;
	if (env->view == NULL)
	{
		env->view = (t_cord **)malloc(sizeof(t_cord *) * env->sz.y);
		if (env->view == NULL)
			ft_error("Could not malloc for the view y co-ords!");
		while (yc < env->sz.y)
		{
			env->view[yc] = (t_cord *)malloc(sizeof(t_cord) * env->sz.x);
			if (env->view[yc] == NULL)
				ft_error("Could not malloc for the view x co-ords!");
			yc++;
		}
	}
	if (env->view)
	{
		ft_apply(env);
		ft_draw(env);
	}
}

void				ft_move_n_scale(t_cord *src, t_cord *dest, t_env *env)
{
	if ((env->project == 1) && (src->z > 0))
	{
		dest->x = ((src->x / src->z) + env->loc.x) * env->zoom;
		dest->y = ((src->y / src->z) + env->loc.y) * env->zoom;
		dest->z = src->z * env->zoom;
	}
	dest->x = (src->x + env->loc.x) * env->zoom;
	dest->y = (src->y + env->loc.y) * env->zoom;
	dest->z = src->z * env->zoom;
}

void				ft_apply(t_env *env)
{
	unsigned int	xc;
	unsigned int	yc;

	yc = 0;
	while (yc < env->sz.y)
	{
		xc = 0;
		while (xc < env->sz.x)
		{
			ft_rotx(&env->model[yc][xc], &env->view[yc][xc], env->rot.x);
			ft_roty(&env->view[yc][xc], &env->view[yc][xc], env->rot.y);
			ft_rotz(&env->view[yc][xc], &env->view[yc][xc], env->rot.z);
			ft_move_n_scale(&env->view[yc][xc], &env->view[yc][xc], env);
			ft_fromndc(&env->view[yc][xc], &env->view[yc][xc]);
			xc++;
		}
		yc++;
	}
}
