/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_darken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:06:22 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/30 22:51:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_canvas_darken(t_app *app, size_t x, size_t y, double percentage)
{
	t_rgb	rgb;

	ft_canvas_pixel_get(app, &rgb, x, y);
	ft_color_darken(&rgb, percentage);
	ft_canvas_pixel_set(app, &rgb, x, y);
}
