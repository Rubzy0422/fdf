/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:19:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/03 20:03:05 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	main(int argc, char **argv)
{
    int	    fd;

    if (argc != 2)
    	ft_error("Usage : ./fdf <map>");
    fd = open (argv[1], O_RDONLY);
    if (fd < 0 || ft_strequ(ft_strrchr(argv[1], '.'), ".fdf") == 0)
    	ft_error("please provide a propper .fdf map");
    ft_envinit(fd, argv[1]);
    return (0);
}

void	ft_error(char *str)
{
    char    *prompt;

    prompt = ft_strjoin("\e[91m", "[ERROR]\t\t\t");
    prompt = ft_strjoin_free(prompt, str, 1, 0);
    prompt = ft_strjoin_free(prompt, "\33[m", 1, 0);
    ft_putendl_fd(prompt, 2);
    free(prompt);
    exit(-1);
}

int	ft_envinit(int fd, char *file)
{
    t_env   env;

    env.mlx = mlx_init();
    env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "FDF");
    env.loc.x = 0;
    env.loc.y = 0;                                                 
    env.rot.x = -81;                                               
    env.rot.y = 90;                                                
    env.rot.z = 90;                                                
    env.zoom = 1;
    env.view = NULL;
    env.model = NULL;
    env.sz = ft_gridsize(file);
    ft_readcordfile(&env, fd);
    ft_imginit(&env, &env.img, WIN_X, WIN_Y);
    ft_create_view(&env);
    ft_handelhooks(&env);
    mlx_loop(env.mlx);
    return (0);
}
