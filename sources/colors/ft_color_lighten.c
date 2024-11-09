/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_lighten.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:26:06 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 22:42:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_lighten(t_rgb *rgb, double percentage)
{
	double	final;

	final = rgb->channel_r + (percentage / 100 * rgb->channel_r);
	rgb->channel_r = ft_ternary_int(final > 255, 255, final);
	final = rgb->channel_g + (percentage / 100 * rgb->channel_g);
	rgb->channel_g = ft_ternary_int(final > 255, 255, final);
	final = rgb->channel_b + (percentage / 100 * rgb->channel_b);
	rgb->channel_b = ft_ternary_int(final > 255, 255, final);
}
