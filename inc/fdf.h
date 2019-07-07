/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:33:02 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/07 01:24:52 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include "keydef.h"
# include			<stdio.h>
# define WIN_X 1024
# define WIN_Y 768

typedef struct		s_cord
{
	float			x;
	float			y;
	float			z;
	int				colo;
}					t_cord;

typedef struct		s_colo
{
	float			r;
	float			g;
	float			b;
}					t_colo;

typedef struct		s_mouse
{
	int				x_old;
	int				y_old;
	int				x_new;
	int				y_new;
}					t_mouse;

typedef struct		s_loc
{
	float			x;
	float			y;
	float			z;
}					t_loc;

typedef struct		s_rot
{
	float			x;
	float			y;
	float			z;
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
	float			zoom;
	float			speed;
	int				project;
	int				do_rot;
	t_sz			sz;
	t_cord			**model;
	t_cord			**view;
	t_img			img;
	t_mouse			mouse;
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
void				ft_fromndc(t_cord *src, t_cord *dest);
void				ft_apply(t_env *env);
void				ft_rotx(t_cord *src, t_cord *dst, float theta);
void				ft_roty(t_cord *src, t_cord *dst, float theta);
void				ft_rotz(t_cord *src, t_cord *dst, float theta);
void				ft_move_n_scale(t_cord *src, t_cord *dest, t_env *env);
void				ft_create_view(t_env *env);
void				ft_draw(t_env *env);
void				ft_drawline(t_img *img, t_cord src, t_cord dst);
void				ft_px_to_img(t_img *img, int colo, int x, int y);
void				ft_imginit(t_env *env, t_img *img, int w, int h);
void				ft_img_to_win(t_env *env, t_img *img);
void				ft_img_clear(t_img *img, int colo);
void				ft_string_proj(t_env *env);
int					ft_mousemove(int x, int y, t_env *env);
int					ft_mousetoggle(int key, t_env *env);
int					ft_ctrl(int key, t_env *env);
int					ft_mouseinit(t_mouse *mouse);
float				ft_zoom_hndl(unsigned int y, unsigned int x);
void				ft_set_colo(t_cord **src, t_cord **dst, t_env *env);
t_colo				hex_to_rgb(int colo);
int					rgb_to_hex(t_colo src);
int					colo_grad(int colo_src, int colo_dst, float perc);
float				ft_perc(t_cord src, t_cord dst, t_cord cnt);
#endif
