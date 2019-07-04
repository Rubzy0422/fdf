/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:03:47 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/04 14:04:12 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
