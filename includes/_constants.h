/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:10:13 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 16:50:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PI					3.14159265359
#define PI_D2P0				1.57079632679
#define PI_X1P5				4.71238898038
#define PI_X2P0				6.28318530718
#define RADIAN				0.01745330000

#define FOV					1.04719755120

#define COLOR_BLACK			255
#define COLOR_WHITE	   		-1

#define KEY_A				65
#define KEY_D				68
#define KEY_E				69
#define KEY_R				82
#define KEY_S				83
#define KEY_W				87
#define KEY_M				77
#define KEY_ESCAPES			256
#define KEY_ARROW_R			262
#define KEY_ARROW_L			263

#define MAX_BUFF_SIZE		100000
#define MAX_CODE_SIZE		64
#define MAX_PATH_SIZE		4097

#define TRUE				1
#define FALSE				0

#define FAILURE		   		-1
#define SUCCESS				1

#define NPOS			   -1

#define TERM_CTRL_CLEAR		"\001\e[1;1H\e[2J\002"
#define TERM_CTRL_RESET		"\001\e[0m\002"

#define TERM_BCOLOR_BLU		"\001\e[1;34m\002"
#define TERM_BCOLOR_CYA		"\001\e[1;36m\002"
#define TERM_BCOLOR_GRN		"\001\e[1;32m\002"
#define TERM_BCOLOR_PUR		"\001\e[1;35m\002"
#define TERM_BCOLOR_RED		"\001\e[1;31m\002"
#define TERM_BCOLOR_WHT		"\001\e[1;37m\002"
#define TERM_BCOLOR_YEL		"\001\e[1;33m\002"
#define TERM_NCOLOR_BLU		"\001\e[0;34m\002"
#define TERM_NCOLOR_CYA		"\001\e[0;36m\002"
#define TERM_NCOLOR_GRN		"\001\e[0;32m\002"
#define TERM_NCOLOR_PUR		"\001\e[0;35m\002"
#define TERM_NCOLOR_RED		"\001\e[0;31m\002"
#define TERM_NCOLOR_WHT		"\001\e[0;37m\002"
#define TERM_NCOLOR_YEL		"\001\e[0;33m\002"
