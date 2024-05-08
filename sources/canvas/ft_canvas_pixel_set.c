/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_pixel_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:33:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/03 13:52:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_canvas_pixel_set(t_app *app, t_rgb *rgb, size_t x, size_t y)
{
	if (rgb->channel_a == 255)
	{
		y = (y * app->win.bytes_width) + x * 4;
		app->rdr.content[y + 0] = rgb->channel_r;
		app->rdr.content[y + 1] = rgb->channel_g;
		app->rdr.content[y + 2] = rgb->channel_b;
		app->rdr.content[y + 3] = 255;
	}
}
