/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:43:34 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/28 00:59:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_window_close() :
*
*	Close the window opened with the "MLX42" library.
*/
void	ft_window_close(t_app *app, t_win *win)
{
	if (app->mlx.mlx != NULL)
		mlx_close_window(app->mlx.mlx);
	win->is_opened = FALSE;
}
