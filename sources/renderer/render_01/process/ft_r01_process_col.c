/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r01_process_col.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:13:37 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 08:20:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_intialize(t_app *app, t_drw *drw);
static void		ft_process(t_app *app, t_drw *drw, uint8_t *texture);
static uint8_t	*ft_get_text_rgba(t_app *app, t_ray *ray);

void	ft_r01_process_col(t_app *app)
{
	t_drw	drw;

	st_drw_initialize(&drw);
	ft_intialize(app, &drw);
	ft_process(app, &drw, ft_get_text_rgba(app, &app->rdr.ray));
}

static void	ft_intialize(t_app *app, t_drw *drw)
{
	st_drw_initialize(drw);
	drw->s = 64 / app->rdr.ray.distance * app->rdr.screen_dst;
	drw->ratio_depth = app->rdr.ray.distance / 64 * app->cfg.ratio_depthblur;
	drw->ratio_scale = (double) drw->s / app->cfg.ratio_texturing;
	if (drw->s < app->win.size_h)
	{
		drw->pos_s.pos_z = app->win.size_h_d2 - (drw->s / 2);
		drw->index_1 = 0;
		drw->s = drw->s + drw->pos_s.pos_z;
	}
	else
	{
		drw->pos_s.pos_z = 0;
		drw->index_1 = (drw->s - app->win.size_h) / 2;
		drw->s = app->win.size_h;
	}
	drw->pos_t.pos_x = (int) app->rdr.ray.offset_t
		* (app->cfg.ratio_texturing / 64);
}

static void	ft_process(t_app *app, t_drw *drw, uint8_t *texture)
{
	while (drw->pos_s.pos_z < drw->s)
	{
		drw->pos_t.pos_z = (int)(drw->index_1++ / drw->ratio_scale);
		ft_texture_pixel_get(app, texture, &drw->rgb, &drw->pos_t);
		ft_color_darken(&drw->rgb, drw->ratio_depth);
		ft_canvas_pixel_set(app, &drw->rgb, app->rdr.ray.count,
			drw->pos_s.pos_z++);
	}
}

static uint8_t	*ft_get_text_rgba(t_app *app, t_ray *ray)
{
	if (ft_tkn_use(app, ray->target_tpe) == 4)
		return (ft_src_use(app, 3));
	else if (ray->dst.dist_h < ray->dst.dist_v)
	{
		if (ray->angle > 0 && ray->angle < PI)
			return (ft_src_use(app, 7));
		else
			return (ft_src_use(app, 6));
	}
	else if (ray->dst.dist_h >= ray->dst.dist_v)
	{
		if ((ray->angle < PI_D2P0 && ray->angle > 0)
			|| (ray->angle > PI_X1P5 && ray->angle < PI_X2P0))
			return (ft_src_use(app, 4));
		else
			return (ft_src_use(app, 8));
	}
	return (NULL);
}
