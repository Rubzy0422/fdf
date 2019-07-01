/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:15:30 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 22:48:30 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	    ft_readcordfile(t_env *env, int fd)
{
    char    *ln;
    char    **content;

    env->sz_x = ft_ln_one(fd);
    env->sz_y = ft_line_count(fd);
    env->model = malloc(sizeof(t_cord **) * env->sz_y * env->sz_x); 
    if ((env->model) == NULL)
    	ft_error("Could'nt malloc for the model co-ords!");
   while (ft_get_next_line(fd, &ln) > 0)
   {
       env->sz_x = ft_wordc(ln);
       content = ft_strsplit(ln, ' ');
       env->model[env->sz_y] = ft_strtocord(env, content, env->sz_y);
       env->sz_y++;
       free(ln);
    }
    close(fd);
    printf("%ld, %ld\n", env->sz_x, env->sz_y);
    if (env->sz_x < 1 && env->sz_y < 1)
    	ft_error("Invalid map was entered!");
}

t_cord	*ft_strtocord(t_env *env, char **content, size_t yc)
{
    unsigned int    xc;

    xc = 0;
    while (xc <= env->sz_x)
    {
//	env->model[xc][yc].x = xc / env->sz_x;
	env->model[xc][yc].z = ft_atof(content[xc]);
//	env->model[xc][yc].y = yc / env->sz_y;
	xc++;
    }
}
