/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:19 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/02 17:25:08 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void		ft_fromndc(t_cord *src, t_cord *dest)
{
	dest->x = src->x * 0.5 * WIN_X;
	dest->y = src->y * 0.5 * WIN_Y;
	dest->x += 0.5 * WIN_X;
	dest->y += 0.5 * WIN_Y;
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
		mlx_clear_window(env->mlx, env->win);
		ft_apply(env);
	}
}
void				ft_move_n_scale(t_cord *src, t_cord *dest, t_env *env)
{
	dest->x = src->x * env->zoom + env->loc.x;
	dest->y = src->y * env->zoom + env->loc.y;
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
		while(xc < env->sz.x)
		{
			ft_move_n_scale(&env->model[yc][xc], &env->view[yc][xc], env);
			ft_rotx(&env->view[yc][xc], &env->view[yc][xc], env->rot.x); 
			ft_roty(&env->view[yc][xc], &env->view[yc][xc], env->rot.y); 
			ft_rotz(&env->view[yc][xc], &env->view[yc][xc], env->rot.z);
			ft_fromndc(&env->view[yc][xc], &env->view[yc][xc]);
			mlx_pixel_put(env->mlx, env->win, env->view[yc][xc].x, env->view[yc][xc].y, 0xfffffff); 		
			printf("%lf, %lf, %lf\n",env->view[yc][xc].x,env->view[yc][xc].y,env->view[yc][xc].z);
			xc++;
		}
		yc++;
	}
}

void				ft_rotx(t_cord *src, t_cord *dst, double theta)
{
	double			s;
	double			c;
	double			temp;

	theta = theta * (M_PI / 180);
	s = sin(theta);
	c = cos(theta);
	temp = s * src->y + c * src->z;
	dst->z = c * src->y - s * src->z;
	dst->y = temp;
	dst->x = src->x;
}

void				ft_roty(t_cord *src, t_cord *dst, double theta)
{
	double			s;
	double			c;
	double			temp;

	theta = theta * (M_PI / 180);
	s = sin(theta);
	c = cos(theta);
	temp = s * src->x + c * src->z;
	dst->z = c * src->x - s * src->z;
	dst->x = temp;
	dst->y = src->y;
}

void				ft_rotz(t_cord *src, t_cord *dst, double theta)
{
	double			s;
	double			c;
	double			temp;

	theta = theta * (M_PI / 180);
	s = sin(theta);
	c = cos(theta);
	temp = s * src->x + c * src->y;
	dst->y = c * src->x - s * src->y;
	dst->x = temp;
	dst->z = src->z;
}
