/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:21:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 22:44:14 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_line_count(int fd)
{
    char	    *ln;
    unsigned int    sz;

    sz = 0;
    while (ft_get_next_line(fd, &ln) > 0)
    {
    	sz++;
    	free(ln);
    }
    close(fd);
    return(sz);
}
