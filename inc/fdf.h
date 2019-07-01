/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:33:02 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 22:05:46 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "keydef.h"

# define WIN_X 1024
# define WIN_Y 768
# define SPEED 5

typedef struct	s_cord
{
    double	x;
    double	y;
    double	z;
    double	colo;
}		t_cord;

typedef struct	s_loc
{
    double	x;
    double	y;
    double	z;
}		t_loc;

typedef struct	s_rot
{
    double	x;
    double	y;
    double	z;
}		t_rot;

typedef struct	s_env
{
    void	*mlx;
    void	*win;
    t_loc	loc;
    t_rot	rot;
    double	zoom;
    size_t  	sz_x;
    size_t	sz_y;
    t_cord	**model;
}		t_env;

int		main(int argc, char **argv);
void		ft_error(char *str);
int		ft_envinit(int fd);


void	    ft_hndhooks(t_env *env);
int	    ft_handelkey(int key, void *param);
int	    ft_handelrotation(int key, t_env *env);
int	    fdf_exit(void *param);
void	    ft_readcordfile(t_env *env, int fd);
t_cord	    *ft_strtocord(t_env *env, char **content, size_t yc);
#endif
