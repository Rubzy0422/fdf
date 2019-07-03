/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:15:30 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/03 19:59:30 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sz				ft_gridsize(char *file)
{
	int				fd;
	t_sz			sz;
	unsigned int	tmp;
	char			*ln;

	sz.x = 0;
	sz.y = 0;
	tmp = 0;
	fd = open(file, O_RDONLY);
	while (ft_get_next_line(fd, &ln) > 0)
	{
		tmp = sz.x;
		sz.x = ft_wordc(ln);
		if (tmp != sz.x && sz.y > 0)
			ft_error("Bad Map was entered!");
		sz.y++;
		free(ln);
	}
	close(fd);
	return (sz);
}

void				ft_readcordfile(t_env *env, int fd)
{
	char			*ln;
	char			**content;
	unsigned int	yc;

	yc = 0;
	env->model = (t_cord **)malloc(sizeof(t_cord*) * env->sz.y);
	if ((env->model) == NULL)
		ft_error("Could'nt malloc for the model co-ords!");
	while (ft_get_next_line(fd, &ln) > 0)
	{
		content = ft_strsplit(ln, ' ');
		env->model[yc] = (t_cord *)malloc(sizeof(t_cord) * env->sz.x);
		ft_strtocord(env, content, yc);
		ft_freearr(content);
		free(ln);
		yc++;
	}
	close(fd);
	if (env->sz.x < 1 || env->sz.y < 1)
		ft_error("Invalid map was entered!");
}

void	ft_strtocord(t_env *env, char **content, unsigned int yc)
{
	unsigned int    xc;
	double		tmpx;
	double		tmpy;

	xc = 0;
	tmpy = (double)yc / env->sz.y;
	while (xc < env->sz.x)
	{
		tmpx = (double)xc / env->sz.x;
		env->model[yc][xc].x = tmpx - (0.5 * tmpx);
		env->model[yc][xc].z = ft_atof(content[xc]);
		env->model[yc][xc].y = tmpy - (0.5 * tmpy);
		xc++;
	}
}
