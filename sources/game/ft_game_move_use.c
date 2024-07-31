/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_move_use.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:04:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/24 17:59:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_move_use(t_app *app)
{
	if (app->gme.target_dst < app->cfg.ratio_actionuse * 64)
	{
		if (ft_tkn_use(app, app->gme.map.map[(int) app->gme.target_pos.pos_z]
				[(int) app->gme.target_pos.pos_x]) == 4)
			app->gme.map.map[(int) app->gme.target_pos.pos_z]
			[(int) app->gme.target_pos.pos_x] = '0';
	}
}
