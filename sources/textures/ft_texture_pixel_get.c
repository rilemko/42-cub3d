/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_pixel_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:33:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/30 22:25:17 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rgb	*ft_texture_pixel_get(t_app *app, uint8_t *texture, t_rgb *rgb,
		t_pos *pos)
{
	size_t	offset;

	offset = (pos->pos_z * app->cfg.ratio_texturing * 4) + pos->pos_x * 4;
	rgb->channel_r = texture[offset + 0];
	rgb->channel_g = texture[offset + 1];
	rgb->channel_b = texture[offset + 2];
	rgb->channel_a = texture[offset + 3];
	return (rgb);
}
