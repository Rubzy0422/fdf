/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:15:30 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/02 09:46:07 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

t_sz				ft_gridsize(char *file)
{
	int				fd;
	t_sz			sz;
	char			*ln;

	sz.x = 0;
	sz.y = 0;
	fd = open(file, O_RDONLY);
	while (ft_get_next_line(fd, &ln) > 0)
	{
		sz.x = ft_wordc(ln);
		sz.y++;
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
    env->model = malloc(sizeof(t_cord) * env->sz.y * env->sz.x); 
    if ((env->model) == NULL)
    	ft_error("Could'nt malloc for the model co-ords!");
   while (ft_get_next_line(fd, &ln) > 0)
   {
       content = ft_strsplit(ln, ' ');
       ft_strtocord(env, content, yc);
       yc++;
       free(ln);
   }
   close(fd);
   ft_freearr(content);
    if (env->sz.x < 1 && env->sz.y < 1)
    	ft_error("Invalid map was entered!");
}

void	ft_strtocord(t_env *env, char **content, unsigned int yc)
{
    unsigned int    xc;

    xc = 0;
    while (xc < env->sz.x)
    {
		//env->model[yc][xc].x = xc / env->sz.x;
		env->model[0][0].z = ft_atof(content[xc]);
		//env->model[yc][xc].y = yc / env->sz.y;
//		printf("x: %lf, y:%lf, z:%lf\n",env->model[0][0].x, env->model[0][0].y,env->model[0][0].z);
		xc++;
    }
}
