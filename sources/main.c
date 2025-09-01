/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:08:54 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 15:11:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_process(t_app *app);
static void	ft_tickrate(void *app);

/*
*	main() :
*
*	Application entry point.
*	Initialize the main objects and call the main process.
*/
int	main(int agc, char **agv, char **env)
{
	t_app	app;

	st_app_initialize(&app, agc, agv, env);
	ft_process(&app);
	ft_app_exit(&app, app.ext.code, app.ext.content);
}

static void	ft_process(t_app *app)
{
	if (app->sts.is_running == TRUE && ft_parse(app) == SUCCESS
		&& ft_window_open(app, &app->mlx, &app->win) == SUCCESS)
	{
		if (app->sts.is_running == TRUE)
		{
			st_ray_initialize(&app->rdr.ray, &app->gme);
			mlx_key_hook(app->mlx.mlx, ft_hook, app);
			mlx_loop_hook(app->mlx.mlx, ft_tickrate, app);
			mlx_loop(app->mlx.mlx);
		}
	}
}

static void	ft_tickrate(void *app)
{
	ft_update((t_app *) app);
	ft_render((t_app *) app);
}
