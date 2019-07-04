/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:47:43 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/04 20:57:53 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# if __APPLE__
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define ARROWUP 126
# define ARROWDOWN 125
# define NUMDOWN 84
# define NUMLEFT 86
# define NUMRIGHT 88
# define NUM_7 89
# define NUM_5 87
# define NUM_9 92
# define NUMUP 91

# elif __linux__
# define A 'a'
# define S 's'
# define D 'd'
# define W 'w'
# define ESC 0xff1b
# define ARROWUP 0xff52
# define ARROWDOWN 0xff54
# define NUMDOWN 0xff99
# define NUMLEFT 0xff96
# define NUMRIGHT 0xff98
# define NUM_7 0xff95
# define NUM_5 0xff9d
# define NUM_9 0xff9a
# define NUMUP 0xff97
# endif
#endif
