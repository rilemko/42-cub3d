/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_byte_h.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:00:59 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/18 20:16:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_color_byte_h(t_rgb *rgb)
{
	double	byte_h;

	byte_h = rgb->channel_r;
	byte_h = ft_ternary_int(byte_h < rgb->channel_g, rgb->channel_g, byte_h);
	byte_h = ft_ternary_int(byte_h < rgb->channel_b, rgb->channel_b, byte_h);
	return (byte_h);
}
