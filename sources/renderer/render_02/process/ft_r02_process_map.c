/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r02_process_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:51:47 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/04 01:55:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_process(t_app *app, t_pos *pos_m, t_pos *pos_s);
static void	ft_cursor(t_app *app);

void	ft_r02_process_map(t_app *app)
{
	t_pos	pos_s;
	t_pos	pos_m;
	size_t	size_x;
	size_t	size_z;

	pos_s.pos_z = app->rdr.hud.map_pos_y;
	pos_m.pos_z = app->gme.dot.pos_z - app->rdr.hud.map_offset;
	size_z = app->win.size_h - app->cfg.hud_offsets;
	size_x = app->rdr.hud.map_sizing + app->cfg.hud_offsets;
	while (pos_s.pos_z < size_z)
	{
		pos_s.pos_x = app->rdr.hud.map_pos_x;
		pos_m.pos_x = app->gme.dot.pos_x - app->rdr.hud.map_offset;
		while (pos_s.pos_x < size_x)
		{
			ft_process(app, &pos_m, &pos_s);
			pos_m.pos_x += 0.05;
			pos_s.pos_x++;
		}
		pos_m.pos_z += 0.05;
		pos_s.pos_z++;
	}
	ft_cursor(app);
}

static void	ft_process(t_app *app, t_pos *pos_m, t_pos *pos_s)
{
	t_tkn	*tkn;

	if (pos_m->pos_x < 0 || pos_m->pos_z < 0
		|| pos_m->pos_z > app->gme.map.size_h
		|| pos_m->pos_x > ft_strlen(app->gme.map.map[(int) pos_m->pos_z]))
		tkn = ft_tkn_get(app, ' ');
	else
		tkn = ft_tkn_get(app,
				app->gme.map.map[(int) pos_m->pos_z][(int) pos_m->pos_x]);
	if (tkn->is_colored == TRUE)
		return (ft_canvas_pixel_set(app,
				&tkn->rgb, pos_s->pos_x, pos_s->pos_z));
	ft_canvas_darken(app, pos_s->pos_x, pos_s->pos_z, app->cfg.hud_opacity);
}

static void	ft_cursor(t_app *app)
{
	size_t			pos_x;
	size_t			pos_y;
	static t_rgb	*rgb;

	if (rgb == NULL)
		rgb = &ft_tkn_get(app, 'E')->rgb;
	pos_y = app->win.size_h - app->rdr.hud.map_sizing_d2 - 24 - 3;
	while (pos_y < app->win.size_h - app->rdr.hud.map_sizing_d2 - 24 + 3)
	{
		pos_x = 24 + app->rdr.hud.map_sizing_d2 - 3;
		while (pos_x < 24 + app->rdr.hud.map_sizing_d2 + 3)
			ft_canvas_pixel_set(app, rgb, pos_x++, pos_y);
		pos_y++;
	}
}
