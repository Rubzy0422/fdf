/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 09:54:40 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/07 18:15:47 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		rgb_to_hex(t_colo colo)
{
	int ret;

	ret = colo.r;
	ret *= 0x100;
	ret += colo.g;
	ret *= 0x100;
	ret += colo.b;	
	return (ret);
}

t_colo	hex_to_rgb(int src)
{
	t_colo	colo;

	colo.r = (src & 0xff0000) / 0x10000;
	colo.g = (src & 0xff00) / 0x100;
	colo.b = (src & 0xff);
	return (colo);
}

int		colo_grad(int colo_src, int colo_dst, float perc)
{
	t_colo	rgb_src;
	t_colo	rgb_dst;
	t_colo	res;
	int		colo;

	rgb_src = hex_to_rgb(colo_src);
	rgb_dst = hex_to_rgb(colo_dst);

	res.r = rgb_src.r + perc * (rgb_dst.r - rgb_src.r); 
	res.g = rgb_src.g + perc * (rgb_dst.g - rgb_src.g);
	res.b = rgb_src.b + perc * (rgb_dst.b - rgb_src.b);

	colo = rgb_to_hex(res);
	return (colo);
}

void	ft_set_colo(t_cord **src, t_cord **dst, t_env *env)
{
	unsigned int	xc;
	unsigned int	yc;

	yc = 0;
	while (yc < env->sz.y)
	{
		xc = 0;
		while (xc < env->sz.x)
		{
			if (src[yc][xc].z < 0)
				dst[yc][xc].colo = 0x0000ff;		
			else if (src[yc][xc].z == 0)
				dst[yc][xc].colo = 0xffffff;	
			else if (src[yc][xc].z > 0 && src[yc][xc].z < 10)
				dst[yc][xc].colo = 0x00ff00;
			else if (src[yc][xc].z >= 10)
				dst[yc][xc].colo = 0xff0000;
		xc++;
		}
		yc++;
	}
}
