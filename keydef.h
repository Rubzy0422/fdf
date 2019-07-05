/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keydef.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:06:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/05 13:45:51 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYDEF_H
# define KEYDEF_H

# if __APPLE__
# define KP_ONE			18
# define KP_TWO			19
# define KP_THREE		20
# define KP_FOUR		21
# define KP_FIVE		23
# define KP_SIX			22
# define KP_SEVEN		26
# define KP_EIGHT		28
# define KP_NINE		25
# define KP_ZERO		29
# define KP_NEG			27
# define KP_POS			24
# define KP_BACK		51
# define KP_Q			12
# define KP_W			13
# define KP_E			14
# define KP_R			15
# define KP_T			17
# define KP_Y			16
# define KP_U			32
# define KP_I			34
# define KP_O			31
# define KP_P			35
# define KP_SQR_BRACK_S	33
# define KP_SQR_BRACK_E	30
# define KP_BACK_SLASH	42
# define KP_A			0
# define KP_S			1
# define KP_D			2
# define KP_F			3
# define KP_G			5
# define KP_H			4
# define KP_J			38
# define KP_K			40
# define KP_L			37
# define KP_COLON		41
# define KP_QUOTE		39
# define KP_ENTER		36
# define KP_Z			6
# define KP_X			7
# define KP_C			8
# define KP_V			9
# define KP_B			11
# define KP_N			45
# define KP_M			46
# define KP_LESSER		43
# define KP_GREATER		47
# define KP_QUESTION	44
# define KP_R_SHIFT		258
# define KP_ARROW_UP	126
# define KP_ARROW_DOWN	125
# define KP_ARROW_LEFT	123
# define KP_ARROW_RIGHT	124
# define KP_NUM_ZERO	82
# define KP_NUM_ONE		83
# define KP_NUM_TWO		84
# define KP_NUM_THREE	85
# define KP_NUM_FOUR	86
# define KP_NUM_FIVE	87
# define KP_NUM_SIX		88
# define KP_NUM_SEVEN	89
# define KP_NUM_EIGHT	91
# define KP_NUM_NINE	92
# elif __linux__
# define KP_ONE			0xffb1
# define KP_TWO			0xffb2
# define KP_THREE		0xffb3
# define KP_FOUR		0xffb4
# define KP_FIVE		0xffb5
# define KP_SIX			0xffb6
# define KP_SEVEN		0xffb7
# define KP_EIGHT		0xffb8
# define KP_NINE		0xffb9
# define KP_ZERO		0xffb0
# define KP_NEG			0xffad
# define KP_POS			0xffab
# define KP_BACK		0xff08
# define KP_Q			'q'
# define KP_W			'w'
# define KP_E			'e'
# define KP_R			'r'
# define KP_T			't'
# define KP_Y			'y'
# define KP_U			'u'
# define KP_I			'i'
# define KP_O			'o'
# define KP_P			'p'
# define KP_SQR_BRACK_S	33
# define KP_SQR_BRACK_E	30
# define KP_BACK_SLASH	42
# define KP_A			'a'
# define KP_S			's'
# define KP_D			'd'
# define KP_F			'f'
# define KP_G			'g'
# define KP_H			'h'
# define KP_J			'j'
# define KP_K			'k'
# define KP_L			'l'
# define KP_COLON		41
# define KP_QUOTE		39
# define KP_ENTER		0xff8d
# define KP_Z			'z'
# define KP_X			'x'
# define KP_C			'c'
# define KP_V			'v'
# define KP_B			'b'
# define KP_N			'n'
# define KP_M			'm'
# define KP_LESSER		43
# define KP_GREATER		47
# define KP_QUESTION	44
# define KP_R_SHIFT		258
# define KP_ARROW_UP	0xff52
# define KP_ARROW_DOWN	0xff54
# define KP_ARROW_LEFT	0xff51
# define KP_ARROW_RIGHT	0xff53
# define KP_NUM_ZERO	0xffb0
# define KP_NUM_ONE		0xffb1
# define KP_NUM_TWO		0xffb2
# define KP_NUM_THREE	0xffb3
# define KP_NUM_FOUR	0xffb4
# define KP_NUM_FIVE	0xffb5
# define KP_NUM_SIX		0xffb6
# define KP_NUM_SEVEN	0xffb7
# define KP_NUM_EIGHT	0xffb8
# define KP_NUM_NINE	0xffb9
# endif
#endif
