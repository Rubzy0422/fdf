/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:57:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/08 11:02:04 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wordc(char *str)
{
	int				iswrd;
	unsigned int	wordc;

	iswrd = 0;
	wordc = 0;
	if (str)
		while (*str != '\0')
		{
			if (iswrd == 0 && *str > ' ')
			{
				iswrd = 1;
				wordc++;
			}
			if (*str <= ' ' && iswrd == 1)
				iswrd = 0;
			str++;
		}
	return (wordc);
}
