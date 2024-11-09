/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_move_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:04:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 16:45:19 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_move_run(t_app *app, double scale)
{
	app->gme.speed_movements = ft_ternary_dbl(scale > 0,
			app->cfg.speed_movements + (app->cfg.speed_movements * scale),
			app->cfg.speed_movements);
}
