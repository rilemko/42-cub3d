/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_pixel_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:33:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/30 22:50:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_canvas_pixel_get(t_app *app, t_rgb *rgb, size_t x, size_t y)
{
	y = (y * app->win.bytes_width) + x * 4;
	rgb->channel_r = app->rdr.content[y + 0];
	rgb->channel_g = app->rdr.content[y + 1];
	rgb->channel_b = app->rdr.content[y + 2];
	rgb->channel_a = app->rdr.content[y + 3];
}
