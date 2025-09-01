/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upd_process_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:35:38 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/31 20:22:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_upd_process_ptr(t_app *app)
{
	int	pos_x;
	int	pos_y;

	if (app->mlx.timestamp - app->hok.ptr_checked_at
		>= app->cfg.delay_hooks_ptr)
	{
		mlx_get_mouse_pos(app->mlx.mlx, &pos_x, &pos_y);
		if (pos_x >= 0 && pos_y >= 0
			&& pos_x < (int) app->win.size_w && pos_y < (int) app->win.size_h
			&& (pos_x != (int) app->win.size_w_d2))
		{
			if (pos_x < (int) app->win.size_w_d2)
				ft_game_move_axe(app, -((double) app->cfg.ratio_mousemove
						* ((app->win.size_w_d2 - pos_x) / 4)));
			else if (pos_x > (int) app->win.size_w_d2)
				ft_game_move_axe(app, +((double) app->cfg.ratio_mousemove
						* ((pos_x - app->win.size_w_d2) / 4)));
			mlx_set_mouse_pos(app->mlx.mlx, app->win.size_w_d2,
				app->win.size_h_d2);
			app->rdr.is_updated = FALSE;
		}
		app->hok.ptr_checked_at = app->mlx.timestamp;
	}
}
