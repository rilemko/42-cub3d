/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rgb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/30 22:24:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_rgb_clear(t_rgb *rgb)
{
	(void) rgb;
}

void	st_rgb_initialize(t_rgb *rgb)
{
	rgb->byte_h = 0.00;
	rgb->byte_l = 0.00;
	rgb->channel_a = 255.00;
	rgb->channel_b = 0.00;
	rgb->channel_g = 0.00;
	rgb->channel_r = 0.00;
}
