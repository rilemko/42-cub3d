/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_process_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:23:39 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 10:15:22 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rt	ft_precheck(t_app *app, t_tkn *tkn);
static void	ft_process(t_app *app, t_tkn *tkn);
static void	ft_terminate(t_app *app);

/*
*	ft_prs_process_map() :
*
*
*/
void	ft_prs_process_map(t_app *app, t_src *src)
{
	t_tkn	*tkn;

	if (app->prs.new.length == 0 && app->gme.map.size_h >= 1)
		return ((void) ft_parse_abort(app, 3.02));
	if (src == NULL)
	{
		while (app->prs.new.buffer[app->prs.ptr.pos_x]
			&& app->prs.sts.is_running == TRUE)
		{
			tkn = ft_tkn_get(app, app->prs.new.buffer[app->prs.ptr.pos_x]);
			if (tkn == NULL)
				return ((void) ft_parse_abort(app, 2.03));
			if (ft_precheck(app, tkn) == SUCCESS)
			{
				ft_process(app, tkn);
				app->prs.ptr.pos_x++;
			}
		}
		ft_terminate(app);
	}
}

static t_rt	ft_precheck(t_app *app, t_tkn *tkn)
{
	if ((tkn->code == 2 || tkn->code == 4
			|| tkn->code == 5 || tkn->code == 6 || tkn->code == 7)
		&& (app->gme.map.size_h == 0
			|| app->prs.ptr.pos_x == 0
			|| app->prs.new.length == app->prs.ptr.pos_x + 1
			|| app->prs.old.length < app->prs.ptr.pos_x
			|| app->prs.nxt.length < app->prs.ptr.pos_x
			|| ft_tkn_use(app, app->prs.old.buffer[app->prs.ptr.pos_x]) == 1
			|| ft_tkn_use(app, app->prs.nxt.buffer[app->prs.ptr.pos_x]) == 1
			|| ft_tkn_use(app, app->prs.new.buffer[app->prs.ptr.pos_x + 1]) == 1
			|| ft_tkn_use(app, app->prs.new.buffer[app->prs.ptr.pos_x - 1]) == 1
		))
		return (ft_parse_abort(app, 3.03));
	return (SUCCESS);
}

static void	ft_process(t_app *app, t_tkn *tkn)
{
	if (tkn->code == 7)
	{
		if (app->gme.pos.pos_x > 0)
			return ((void) ft_parse_abort(app, 2.04));
		app->gme.dot.pos_x = app->prs.ptr.pos_x + 0.5;
		app->gme.dot.pos_z = app->gme.map.size_h + 0.5;
		app->gme.pos.pos_x = app->prs.ptr.pos_x * 64 + 32;
		app->gme.pos.pos_z = app->gme.map.size_h * 64 + 32;
		if (app->prs.new.buffer[app->prs.ptr.pos_x] == 'E')
			app->gme.angle = 0;
		else if (app->prs.new.buffer[app->prs.ptr.pos_x] == 'N')
			app->gme.angle = PI_D2P0;
		else if (app->prs.new.buffer[app->prs.ptr.pos_x] == 'O')
			app->gme.angle = PI;
		else if (app->prs.new.buffer[app->prs.ptr.pos_x] == 'S')
			app->gme.angle = PI_X1P5;
		app->prs.new.buffer[app->prs.ptr.pos_x] = '0';
	}
}

static void	ft_terminate(t_app *app)
{
	ft_strlcat(app->gme.map.buffer, app->prs.new.buffer, MAX_BUFF_SIZE);
	ft_strlcat(app->gme.map.buffer, ";", MAX_BUFF_SIZE);
	app->gme.map.size_h += 1;
	app->gme.map.size_w = ft_ternary_int(
			app->prs.ptr.pos_x > (int) app->gme.map.size_w,
			app->prs.ptr.pos_x, app->gme.map.size_w);
	if (app->prs.is_complete == TRUE)
	{
		if (app->gme.pos.pos_x == 0)
			return ((void) ft_parse_abort(app, 3.04));
		app->gme.map.map = ft_split(app->gme.map.buffer, ';');
	}
}
