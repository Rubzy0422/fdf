/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:29:26 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/06 17:25:38 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_to_win(t_env *env, t_img *img)
{
	mlx_put_image_to_window(env->mlx, env->win, img->ptr_img,
	img->crd.x, img->crd.y);
}

void	ft_img_clear(t_img *img, int colo)
{
	int *data;
	int i;

	data = (int*)img->raw_data;
	i = 0;
	while (i < (img->w * img->h))
	{
		data[i] = colo;
		i++;
	}
}

void	ft_px_to_img(t_img *img, int colo, int x, int y)
{
	int *data;

	if (x >= img->w || x < 0)
		return ;
	if (y >= img->h || y < 0)
		return ;
	data = (int *)&img->raw_data[x * 4 + y * img->lnsz];
	*data = colo;
}

void	ft_imginit(t_env *env, t_img *img, int w, int h)
{
	img->ptr_img = mlx_new_image(env->mlx, w, h);
	img->raw_data = mlx_get_data_addr(img->ptr_img, &img->bpp, &img->lnsz,
	&img->endian);
	img->w = w;
	img->h = h;
	img->crd.x = 0;
	img->crd.y = 0;
	ft_img_clear(img, 0x000000);
}
