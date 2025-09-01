/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_app.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/04 18:26:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_rt	st_app_validate(t_app *app, int agc);

void	st_app_clear(t_app *app)
{
	ft_lstclear(&app->_errs, st_err_clear);
	ft_lstclear(&app->_keys, st_key_clear);
	ft_lstclear(&app->_srcs, st_src_clear);
	ft_lstclear(&app->_tkns, st_tkn_clear);
	st_win_clear(&app->win);
	st_sts_clear(&app->sts);
	st_rdr_clear(&app->rdr);
	st_prs_clear(&app->prs);
	st_mlx_clear(&app->mlx);
	st_hok_clear(&app->hok);
	st_gme_clear(&app->gme);
	st_ext_clear(&app->ext);
	st_cfg_clear(&app->cfg);
	st_arg_clear(&app->arg);
}

void	st_app_initialize(t_app *app, int agc, char **agv, char **env)
{
	app->_ = &agv[0][2];
	app->_errs = NULL;
	app->_keys = NULL;
	app->_rdrs = NULL;
	app->_srcs = NULL;
	app->_tkns = NULL;
	st_arg_initialize(&app->arg, agv, env);
	st_cfg_initialize(&app->cfg);
	st_ext_initialize(&app->ext);
	st_gme_initialize(&app->gme, &app->cfg);
	st_hok_initialize(&app->hok);
	st_mlx_initialize(&app->mlx);
	st_prs_initialize(&app->prs);
	st_rdr_initialize(&app->rdr, &app->cfg, &app->gme);
	st_sts_initialize(&app->sts);
	st_win_initialize(&app->win, &app->cfg);
	ft_bootstrap(app);
	st_app_validate(app, agc);
}

static t_rt	st_app_validate(t_app *app, int agc)
{
	if (agc == 1 || agc > 2)
		return (ft_app_abort(app, 1.01));
	if (ft_arraysize((void **) app->arg.env) == 0)
		return (ft_app_abort(app, 1.02));
	if (ft_strmatch(app->cfg.format_maps, app->arg.agv[1]) == FALSE)
		return (ft_app_abort(app, 1.03));
	return (SUCCESS);
}
