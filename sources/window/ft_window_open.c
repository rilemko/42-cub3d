/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:12:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/25 15:11:33 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_window_open() :
*
*	Initialize the "MLX42" library, open a centered window with a 
*	width of { win->size_w } pixels and height of { win->size_h } pixels.
*/
t_rt	ft_window_open(t_app *app, t_mlx *mlx, t_win *win)
{
	int32_t	screen_h;
	int32_t	screen_w;

	if (mlx->mlx == NULL)
	{
		mlx->mlx = mlx_init(win->size_w, win->size_h, app->_, FALSE);
		if (mlx->mlx == NULL)
			return (ft_app_abort(app, 4.01));
		win->canvas = mlx_new_image(app->mlx.mlx, win->size_w, win->size_h);
		if (win->canvas == NULL)
			return (ft_window_close(app, win), ft_app_abort(app, 4.03));
		mlx_image_to_window(app->mlx.mlx, win->canvas, 0, 0);
		mlx_get_monitor_size(0, &screen_w, &screen_h);
		mlx_set_cursor_mode(mlx->mlx, MLX_MOUSE_HIDDEN);
		mlx_set_window_pos(mlx->mlx,
			(screen_w / 2) - (win->size_w / 2),
			(screen_h / 2) - (win->size_h / 2));
		ft_strlcpy(win->title, app->_, MAX_CODE_SIZE);
		app->rdr.content = win->canvas->pixels;
		win->is_opened = TRUE;
		win->bytes_width = win->size_w * 4;
		win->bytes_total = win->bytes_width * win->size_h;
		ft_memset(app->rdr.content, 255, win->bytes_total);
	}
	return (SUCCESS);
}
