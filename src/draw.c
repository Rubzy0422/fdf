/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:40:01 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/03 15:08:27 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	ft_drawline(t_img *img, t_cord src, t_cord dst)
{
	t_cord		diff;
	t_cord		i;
	int			pixel;
	double		tmp;

	diff.x = fabs(dst.x - src.x);
	diff.y = fabs(dst.y - src.y);
	tmp = (diff.x > diff.y) ? diff.x : diff.y;
	pixel = (!round(tmp)) ? 1 : round(tmp);
	i.x = diff.x / tmp * (src.x < dst.x ? 1: -1);
	i.y = diff.y / tmp * (src.y < dst.y ? 1: -1);

	while (pixel--)
	{
		if ((src.x > WIN_X && src.x < 0) && (src.y > WIN_Y && src.y < 0))
			tmp = 0;
		ft_px_to_img(img, 0xffffff, src.x, src.y);
		src.x += i.x;
		src.y += i.y;
	}
}

void	ft_draw(t_env *env)
{
	unsigned int xc;
	unsigned int yc;

	yc = 0;
	ft_img_clear(&env->img, 0x000000);	
	while (yc < env->sz.y)
	{
		xc = 0;
		while (xc < env->sz.x)
		{
			ft_drawline(&env->img, env->view[yc][xc], env->view[yc][xc + 1]);
			if (yc + 1 < env->sz.y)
				ft_drawline(&env->img, env->view[yc][xc], env->view[yc +1][xc]);
			xc++;
		}
		yc++;
	}
	ft_img_to_win(env, &env->img);
}
