/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_swap_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:04:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/04 01:54:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_swap_map(t_app *app, double scale)
{
	if ((scale > 0 && app->rdr.hud.map_sizing == app->cfg.hud_size_def)
		|| (scale < 0 && app->rdr.hud.map_sizing > app->cfg.hud_size_def))
	{
		app->rdr.hud.map_sizing = ft_ternary_dbl(scale > 0,
				app->cfg.hud_size_def + (app->cfg.hud_size_def * scale),
				app->cfg.hud_size_def);
		app->rdr.hud.map_offset = app->rdr.hud.map_sizing / 20.00 / 2.00;
		app->rdr.hud.map_pos_x = app->cfg.hud_offsets;
		app->rdr.hud.map_pos_y = app->win.size_h - app->rdr.hud.map_sizing
			- app->cfg.hud_offsets;
		app->rdr.hud.map_sizing_d2 = app->rdr.hud.map_sizing / 2;
	}
}
