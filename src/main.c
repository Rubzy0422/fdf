/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 09:50:37 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/08 08:00:14 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_error("Usage : ./fdf <map>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || ft_strequ(ft_strrchr(argv[1], '.'), ".fdf") == 0)
		ft_error("please provide a propper .fdf map");
	ft_envinit(fd, argv[1]);
	return (0);
}

void		ft_error(char *str)
{
	char	*prompt;

	prompt = ft_strjoin("\e[91m", "[ERROR]\t\t\t");
	prompt = ft_strjoin_free(prompt, str, 1, 0);
	prompt = ft_strjoin_free(prompt, "\33[m", 1, 0);
	ft_putendl_fd(prompt, 2);
	free(prompt);
	exit(-1);
}

int			ft_envinit(int fd, char *file)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "FDF");
	env.sz = ft_gridsize(file);
	env.loc.x = 0;
	env.loc.y = 0;
	env.rot.x = 275;
	env.rot.y = 90;
	env.rot.z = 45;
	env.do_rot = 0;
	env.speed = 2;
	env.zoom = ft_zoom_hndl(env.sz.y, env.sz.x);
	ft_mouseinit(&env.mouse);
	env.view = NULL;
	env.model = NULL;
	ft_readcordfile(&env, fd);
	ft_imginit(&env, &env.img, WIN_X, WIN_Y);
	ft_create_view(&env);
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
	return (0);
}

void		ft_string_proj(t_env *env)
{
	if ((env->rot.x == 275) && (env->rot.y == 90) && (env->rot.z == 45))
		mlx_string_put(env->mlx, env->win, 10, 10, 0xf00aaff, "ISO");
	else
		mlx_string_put(env->mlx, env->win, 10, 10, 0xfeeff00, "ORTH PROJECT");
}
