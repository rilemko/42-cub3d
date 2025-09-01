/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r00_process_flr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:09:13 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/04 15:03:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_r00_process_flr(t_app *app, t_rgb *rgb)
{
	double	higher;
	int		passes;
	size_t	x;
	size_t	y;

	passes = 0;
	higher = app->win.size_h_d2 / rgb->byte_h;
	higher = ft_ternary_int(higher > 0, higher, 0);
	y = app->win.size_h - 1;
	while (y > app->win.size_h_d2 - 1)
	{
		x = 0;
		if (passes++ > higher)
		{
			ft_color_darken(rgb, app->cfg.ratio_gradients);
			passes = 0;
		}
		while (x < app->win.size_w)
			ft_canvas_pixel_set(app, rgb, x++, y);
		y--;
	}
}
