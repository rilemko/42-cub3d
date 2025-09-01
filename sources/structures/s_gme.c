/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_gme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/05 09:56:38 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_gme_clear(t_gme *gme)
{
	st_pos_clear(&gme->pos);
	st_map_clear(&gme->map);
	st_pos_clear(&gme->target_pos);
	st_pos_clear(&gme->dot);
}

void	st_gme_initialize(t_gme *gme, t_cfg *cfg)
{
	gme->angle = 0.00;
	gme->collision = cfg->collision;
	gme->target_dst = 0.00;
	gme->speed_movements = cfg->speed_movements;
	gme->speed_rotations = cfg->speed_rotations;
	st_pos_initialize(&gme->dot);
	st_pos_initialize(&gme->target_pos);
	st_map_initialize(&gme->map);
	st_pos_initialize(&gme->pos);
}
