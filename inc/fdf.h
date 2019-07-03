/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:33:02 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/03 21:34:21 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include "keydef.h"

# define WIN_X 1024
# define WIN_Y 768
# define SPEED 2

typedef struct		s_cord
{
    double			x;
    double			y;
    double			z;
    double			colo;
}					t_cord;

typedef struct		s_loc
{
    double			x;
    double			y;
    double			z;
}					t_loc;

typedef struct		s_rot
{
    double			x;
    double			y;
    double			z;
}					t_rot;

typedef struct		s_sz
{
	unsigned int	x;
	unsigned int	y;
}					t_sz;

typedef struct		s_img
{
	void			*ptr_img;
	int				bpp;
	int				lnsz;
	int				endian;
	char			*raw_data;
	int				w;
	int				h;
	t_cord			crd;
}					t_img;

typedef struct		s_env
{
    void			*mlx;
    void			*win;
    t_loc			loc;
    t_rot			rot;
    double			zoom;
    t_sz			sz;
    t_cord			**model;
	t_cord			**view;
	t_img			img;
}					t_env;

int					main(int argc, char **argv);
void				ft_error(char *str);
int					ft_envinit(int fd, char *file);
void				ft_handelhooks(t_env *env);
int					ft_handelkey(int key, void *param);
int					ft_handelrotation(int key, t_env *env);
int					fdf_exit(void *param);
t_sz				ft_gridsize(char *file);
void				ft_readcordfile(t_env *env, int fd);
void				ft_strtocord(t_env *env, char **content, unsigned int yc);
void				ft_delete_map(t_cord **map, t_env *env);
void				ft_fromndc(t_cord *src, t_cord *dst);
void				ft_apply(t_env *env);
void				ft_rotx(t_cord *src, t_cord *dst, double theta);
void				ft_roty(t_cord *src, t_cord *dst, double theta);
void				ft_rotz(t_cord *src, t_cord *dst, double theta);
void				ft_move_n_scale(t_cord *src, t_cord *dest, t_env *env);
void				ft_create_view(t_env *env);
void				ft_draw(t_env *env);
void				ft_drawline(t_img *img, t_cord src, t_cord dst);
void				ft_px_to_img(t_img *img, int colo, int x, int y);
void				ft_imginit(t_env *env, t_img * img, int w, int h);
void				ft_img_to_win(t_env *env, t_img *img);
void				ft_img_clear(t_img *img, int colo);
#endif
