/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_lighten.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:06:22 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 22:44:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_canvas_lighten(t_app *app, size_t x, size_t y, double percentage)
{
	t_rgb	rgb;

	ft_canvas_pixel_get(app, &rgb, x, y);
	ft_color_lighten(&rgb, percentage);
	ft_canvas_pixel_set(app, &rgb, x, y);
}
