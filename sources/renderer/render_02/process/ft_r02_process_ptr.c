/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r02_process_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:51:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/03 17:30:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_r02_process_ptr(t_app *app)
{
	t_rgb	rgb;
	size_t	pos_x;
	size_t	pos_y;

	rgb.channel_a = 255;
	rgb.channel_b = 255;
	rgb.channel_g = 255;
	rgb.channel_r = 255;
	pos_x = app->win.size_w_d2 - 9;
	pos_y = app->win.size_h_d2;
	while (pos_x++ < app->win.size_w_d2 + 9)
		ft_canvas_pixel_set(app, &rgb, pos_x, pos_y);
	pos_x = app->win.size_w_d2;
	pos_y = app->win.size_h_d2 - 9;
	while (pos_y++ < app->win.size_h_d2 + 9)
		ft_canvas_pixel_set(app, &rgb, pos_x, pos_y);
}
