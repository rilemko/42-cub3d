/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_byte_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:00:59 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/18 20:16:29 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_color_byte_l(t_rgb *rgb)
{
	double	byte_l;

	byte_l = rgb->channel_r;
	byte_l = ft_ternary_int(byte_l > rgb->channel_g, rgb->channel_g, byte_l);
	byte_l = ft_ternary_int(byte_l > rgb->channel_b, rgb->channel_b, byte_l);
	return (byte_l);
}
