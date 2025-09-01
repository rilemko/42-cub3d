/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:49 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 15:40:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_dispatch(t_app *app);
static void	ft_process(t_app *app);
static t_rt	ft_precheck(t_app *app, t_src *src, const char *token);
static t_rt	ft_validate(t_app *app);

/*
*	ft_parse() :
*
*
*/
t_rt	ft_parse(t_app *app)
{
	if (ft_parse_open(app) == SUCCESS)
	{
		while (ft_parse_read(app) == SUCCESS
			&& app->prs.sts.is_running == TRUE)
		{
			ft_dispatch(app);
			if (app->prs.sts.is_running == TRUE
				&& app->prs.is_complete == TRUE)
				return (ft_validate(app));
		}
	}
	return (FAILURE);
}

static void	ft_dispatch(t_app *app)
{
	if (app->prs.count_index == app->prs.count_total)
	{
		if (app->prs.new.length > 0 || app->gme.map.size_h > 0)
			return (ft_prs_process_map(app, NULL));
	}
	else if (app->prs.new.length > 0)
	{
		ft_parse_skip(app, FALSE);
		if (app->prs.ptr.pos_x < app->prs.new.length)
			return (ft_process(app));
		app->prs.ptr.pos_x = 0;
		ft_parse_abort(app, 2.01);
	}
}

static void	ft_process(t_app *app)
{
	char	token[MAX_CODE_SIZE];
	t_src	*src;

	ft_parse_reap(app, token);
	src = ft_src_get(app, token);
	if (ft_precheck(app, src, token) == SUCCESS)
	{
		ft_parse_skip(app, TRUE);
		src->callback(app, src);
		src->is_set = TRUE;
		app->prs.count_index++;
	}
}

static t_rt	ft_precheck(t_app *app, t_src *src, const char *token)
{
	size_t	start;

	if (ft_strlen(token) > 3)
		return (ft_parse_abort(app, 2.13));
	if (src == NULL)
		return (ft_parse_abort(app, 2.03));
	if (src->is_set == TRUE)
		return (ft_parse_abort(app, 2.04));
	start = app->prs.ptr.pos_x;
	ft_parse_skip(app, TRUE);
	if (app->prs.ptr.pos_x >= app->prs.new.length)
		return (ft_parse_abort(app, 2.05));
	ft_parse_skip(app, TRUE);
	if (app->prs.ptr.pos_x < app->prs.new.length)
		return (ft_parse_abort(app, 2.06));
	app->prs.ptr.pos_x = start;
	return (SUCCESS);
}

static t_rt	ft_validate(t_app *app)
{
	if (app->prs.count_index < app->prs.count_total)
		return (ft_parse_abort(app, 2.02));
	if (app->gme.map.size_h == 0)
		return (ft_parse_abort(app, 3.01));
	return (SUCCESS);
}
