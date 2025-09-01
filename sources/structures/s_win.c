/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_win.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/02 21:52:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_win_clear(t_win *win)
{
	(void) win;
}

void	st_win_initialize(t_win *win, t_cfg *cfg)
{
	win->bytes_total = 0;
	win->bytes_width = 0;
	win->canvas = NULL;
	win->framerate = 0;
	win->is_opened = FALSE;
	win->size_h = cfg->win_size_h;
	win->size_w = cfg->win_size_w;
	win->size_h_d2 = cfg->win_size_h / 2;
	win->size_w_d2 = cfg->win_size_w / 2;
	win->tick_count = 0;
	win->tick_delta = 0;
	ft_bzero(win->title, MAX_CODE_SIZE);
}
