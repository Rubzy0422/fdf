/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:19 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/02 12:14:05 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_fromndc(t_cord *src, t_cord *dest)
{
	dest->x = src->x * 0.5 * WIN_X;
	dest->y = src->y * 0.5 * WIN_Y;
	dest->x += 0.5 * WIN_X;
	dest->y += 0.5 * WIN_Y;

}

void				ft_delete_map(t_cord **map, t_env *env)
{
	unsigned int	xc;
	unsigned int	yc;

	xc = 0;
	yc = 0;
	while (yc < env->sz.y)
	{
		while (xc < env->sz.x)
			free(&map[yc][xc]);
		free(&map[yc]);
	}
	free(map);
}

void				ft_apply(t_env *env)
{
	unsigned int	xc;
	unsigned int	yc;

	xc = 0;
	yc = 0;
	while (yc < env->sz.y)
	{
		while(xc < env->sz.x)
		{
			ft_rotx(&env->model[yc][xc], &env->model[yc][xc], env->rot.x); 
			ft_roty(&env->model[yc][xc], &env->model[yc][xc], env->rot.y); 
			ft_rotz(&env->model[yc][xc], &env->model[yc][xc], env->rot.z);
			ft_fromndc(&env->model[yc][xc], &env->model[yc][xc]);
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
