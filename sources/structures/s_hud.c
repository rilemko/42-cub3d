/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hud.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:04:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_hud_clear(t_hud *hud)
{
	(void) hud;
}

void	st_hud_initialize(t_hud *hud, t_cfg *cfg)
{
	hud->map_sizing = cfg->hud_size_def;
	hud->map_offset = (hud->map_sizing / (double) 20 / (double) 2);
	hud->map_pos_x = cfg->hud_offsets;
	hud->map_pos_y = cfg->win_size_h - hud->map_sizing - cfg->hud_offsets;
	hud->map_sizing_d2 = hud->map_sizing / 2;
}
