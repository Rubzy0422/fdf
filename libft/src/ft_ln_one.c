/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ln_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:26:08 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 22:44:55 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ln_one(int fd)
{
    char	    *ln;
    unsigned int    tmp;

    if (ft_get_next_line(fd, &ln) > 0)
    {
	tmp = ft_wordc(ln);
	free(ln);
    }
    close(fd);
    return (tmp);
}
