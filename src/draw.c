/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:28:47 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/06 18:04:02 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_perc(t_cord src, t_cord dst, t_cord cnt)
{
	double expect;
	double curr;

	expect = sqrt(pow((dst.x - src.x), 2) + pow((dst.y - src.y), 2));
	curr = sqrt(pow((dst.x - cnt.x), 2) + pow((dst.y - cnt.y), 2));
	return ((((expect - curr) / expect) * 100));

}

void	ft_drawline(t_img *img, t_cord src, t_cord dst)
{
	t_cord		diff;
	t_cord		cnt;
	t_cord		i;
	int			pixel;
	double		tmp;

	cnt = src;
	diff.x = fabs(dst.x - cnt.x);
	diff.y = fabs(dst.y - cnt.y);
	tmp = (diff.x > diff.y) ? diff.x : diff.y;
	pixel = (!round(tmp)) ? 1 : round(tmp);
	i.x = diff.x / tmp * (cnt.x < dst.x ? 1 : -1);
	i.y = diff.y / tmp * (cnt.y < dst.y ? 1 : -1);
	while (pixel--)
	{
		if ((cnt.x > WIN_X && cnt.x < 0) && (cnt.y > WIN_Y && cnt.y < 0))
			tmp = 0;
		ft_px_to_img(img, colo_grad(src.colo, dst.colo,
		ft_perc(src, dst, cnt)), cnt.x, cnt.y);
		cnt.x += i.x;
		cnt.y += i.y;
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
			if ((xc + 1) < env->sz.x)
				ft_drawline(&env->img, env->view[yc][xc + 1],
				env->view[yc][xc]);
			if ((yc + 1) < env->sz.y)
				ft_drawline(&env->img, env->view[yc][xc],
				env->view[yc + 1][xc]);
			xc++;
		}
		yc++;
	}
	ft_img_to_win(env, &env->img);
	ft_string_proj(env);
}
