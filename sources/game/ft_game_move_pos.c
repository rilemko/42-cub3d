/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_move_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:04:42 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/05 18:00:14 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_game_move_pos_x(t_app *app, double pos_x);
static void	ft_game_move_pos_z(t_app *app, double pos_z);

t_rt	ft_check(t_app *app, t_pos *nxt)
{
	int	code_x;
	int	code_z;

	if (app->cfg.collision == FALSE)
		return (SUCCESS);
	code_x = ft_tkn_use(app, app->gme.map.map[(int) app->gme.dot.pos_z]
		[(int) nxt->pos_x]);
	code_z = ft_tkn_use(app, app->gme.map.map[(int) nxt->pos_z]
		[(int) app->gme.dot.pos_x]);
	if ((code_x == 2 || code_x == 6) && (code_z == 2 || code_z == 6))
		return (SUCCESS);
	return (FAILURE);
}

void	ft_game_move_pos(t_app *app, double pos_x, double pos_z)
{
	if (pos_z != 0)
		return (ft_game_move_pos_z(app, pos_z));
	return (ft_game_move_pos_x(app, pos_x));
}

static void	ft_game_move_pos_x(t_app *app, double pos_x)
{
	t_pos	nxt;
	double	speed;

	speed = app->gme.speed_movements / 2;
	if (pos_x > 0)
	{
		nxt.pos_x = (pos_x * (app->gme.pos.pos_x - (cos(app->gme.angle
							+ PI_D2P0) * speed))) / 64;
		nxt.pos_z = (pos_x * (app->gme.pos.pos_z + (sin(app->gme.angle
							+ PI_D2P0) * speed))) / 64;
	}
	else
	{
		nxt.pos_x = (-pos_x * (app->gme.pos.pos_x + (cos(app->gme.angle
							+ PI_D2P0) * speed))) / 64;
		nxt.pos_z = (-pos_x * (app->gme.pos.pos_z - (sin(app->gme.angle
							+ PI_D2P0) * speed))) / 64;
	}
	if (ft_check(app, &nxt) == SUCCESS)
	{
		app->gme.dot.pos_x = nxt.pos_x;
		app->gme.dot.pos_z = nxt.pos_z;
		app->gme.pos.pos_x = nxt.pos_x * 64;
		app->gme.pos.pos_z = nxt.pos_z * 64;
	}
}

static void	ft_game_move_pos_z(t_app *app, double pos_z)
{
	t_pos	nxt;

	if (pos_z > 0)
	{
		nxt.pos_x = (pos_z * (app->gme.pos.pos_x + cos(app->gme.angle)
					* app->gme.speed_movements)) / 64;
		nxt.pos_z = (pos_z * (app->gme.pos.pos_z - sin(app->gme.angle)
					* app->gme.speed_movements)) / 64;
	}
	else
	{
		nxt.pos_x = (-pos_z * (app->gme.pos.pos_x - cos(app->gme.angle)
					* app->gme.speed_movements)) / 64;
		nxt.pos_z = (-pos_z * (app->gme.pos.pos_z + sin(app->gme.angle)
					* app->gme.speed_movements)) / 64;
	}
	if (ft_check(app, &nxt) == SUCCESS)
	{
		app->gme.dot.pos_x = nxt.pos_x;
		app->gme.dot.pos_z = nxt.pos_z;
		app->gme.pos.pos_x = nxt.pos_x * 64;
		app->gme.pos.pos_z = nxt.pos_z * 64;
	}
}
