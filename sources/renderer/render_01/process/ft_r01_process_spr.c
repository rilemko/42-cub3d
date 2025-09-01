/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r01_process_spr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:13:37 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 14:09:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_sortlist(t_app *app);
static void	ft_intialize(t_app *app, t_drw *drw, t_spr *spr);
static void	ft_process(t_app *app, t_drw *drw, t_spr *spr, uint8_t *texture);

void	ft_r01_process_spr(t_app *app)
{
	t_lst	*lst;
	t_drw	drw;

	ft_sortlist(app);
	lst = app->rdr._sprs;
	while (lst != NULL)
	{
		ft_intialize(app, &drw, lst->content);
		ft_process(app, &drw, lst->content, ft_src_use(app, 5));
		lst = lst->next;
	}
	ft_lstclear(&app->rdr._sprs, st_spr_clear);
}

static void	ft_sortlist(t_app *app)
{
	t_spr	*temporary;
	t_lst	*lst_1;
	t_lst	*lst_2;

	lst_1 = app->rdr._sprs;
	while (lst_1 != NULL)
	{
		lst_2 = lst_1;
		while (lst_2 != NULL)
		{
			if (((t_spr *) lst_1->content)->distance
				< ((t_spr *) lst_2->content)->distance)
			{
				temporary = lst_1->content;
				lst_1->content = lst_2->content;
				lst_2->content = temporary;
			}
			lst_2 = lst_2->next;
		}
		lst_1 = lst_1->next;
	}
}

static void	ft_intialize(t_app *app, t_drw *drw, t_spr *spr)
{
	st_drw_initialize(drw);
	drw->ratio_depth = spr->distance / 64 * app->cfg.ratio_depthblur;
	drw->ratio_scale = (double) spr->total_h / app->cfg.ratio_texturing;
	drw->pos_s.pos_x = 0;
	drw->pos_t.pos_x = (int) app->rdr.ray.offset_t
		* (app->cfg.ratio_texturing / 64);
	drw->s = app->cfg.ratio_texturing * drw->ratio_scale;
	drw->s_d2 = drw->s / 2;
}

static void	ft_process(t_app *app, t_drw *drw, t_spr *spr, uint8_t *texture)
{
	while (drw->pos_s.pos_x < drw->s)
	{
		drw->index_1 = drw->pos_s.pos_x + spr->pos_s.pos_x - drw->s_d2;
		if (drw->index_1 > 0 && drw->index_1 < app->win.size_w
			&& app->rdr.ray.hits[(int) drw->index_1] > spr->distance)
		{
			drw->pos_s.pos_z = 0;
			drw->pos_t.pos_x = (int)(drw->pos_s.pos_x / drw->ratio_scale);
			while (drw->pos_s.pos_z < drw->s)
			{
				drw->index_2 = drw->pos_s.pos_z + spr->pos_s.pos_z - drw->s_d2;
				if (drw->index_2 > 0 && drw->index_2 < app->win.size_h)
				{
					drw->pos_t.pos_z = (int)(drw->pos_s.pos_z
							/ drw->ratio_scale);
					ft_texture_pixel_get(app, texture, &drw->rgb, &drw->pos_t);
					ft_color_darken(&drw->rgb, drw->ratio_depth);
					ft_canvas_pixel_set(app, &drw->rgb, drw->index_1,
						drw->index_2);
				}
				drw->pos_s.pos_z++;
			}
		}
		drw->pos_s.pos_x++;
	}
}
