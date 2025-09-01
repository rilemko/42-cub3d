/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upd_process_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:35:38 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/08 18:02:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_upd_process_win(t_app *app)
{
	char	title[MAX_CODE_SIZE];
	char	*framerate;

	if (app->mlx.timestamp - app->win.tick_delta
		>= 1)
	{
		app->win.framerate = app->win.tick_count;
		app->win.tick_delta = app->mlx.timestamp;
		app->win.tick_count = 0;
		ft_strlcpy(title, app->win.title, MAX_CODE_SIZE);
		ft_strlcat(title, " (FPS: ", MAX_CODE_SIZE);
		framerate = ft_itoa(app->win.framerate);
		ft_strlcat(title, framerate, MAX_CODE_SIZE);
		ft_free((void *) framerate);
		ft_strlcat(title, ")", MAX_CODE_SIZE);
		mlx_set_window_title(app->mlx.mlx, title);
	}
	else
		app->win.tick_count++;
}
