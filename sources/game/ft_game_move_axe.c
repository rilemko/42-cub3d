/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_move_axe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:04:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/05 17:43:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_move_axe(t_app *app, double axe_x)
{
	if (axe_x > 0)
	{
		app->gme.angle = ft_fix_angle(app->gme.angle
				- axe_x * (app->gme.speed_rotations / 100));
	}
	else
	{
		app->gme.angle = ft_fix_angle(app->gme.angle
				+ -axe_x * (app->gme.speed_rotations / 100));
	}
}
