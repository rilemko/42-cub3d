/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cfg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 16:43:40 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_cfg_clear(t_cfg *cfg)
{
	(void) cfg;
}

void	st_cfg_initialize(t_cfg *cfg)
{
	cfg->collision = TRUE;
	cfg->delay_animation = 0.150;
	cfg->delay_hooks_key = 0.005;
	cfg->delay_hooks_ptr = 0.010;
	cfg->folder_maps = "maps";
	cfg->folder_srcs = "maps/assets";
	cfg->format_maps = "*.cub";
	cfg->format_srcs = "*.png";
	cfg->fov = 60;
	cfg->hud_opacity = 80;
	cfg->hud_offsets = 24;
	cfg->hud_size_def = 200;
	cfg->ratio_actionuse = 1;
	cfg->ratio_depthblur = 9.500;
	cfg->ratio_gradients = 1.500;
	cfg->ratio_hud_zooms = 2.500;
	cfg->ratio_mousemove = 0.180;
	cfg->ratio_speed_run = 0.9;
	cfg->ratio_texturing = 512;
	cfg->speed_movements = 2.5;
	cfg->speed_rotations = 2.0;
	cfg->win_size_h = 675;
	cfg->win_size_w = 1200;
}
