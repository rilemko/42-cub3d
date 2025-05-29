/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:18:50 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 12:52:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_process(t_app *app, t_spr *spr, t_pos *pos);

t_spr	*ft_spr_add(t_app *app, t_pos *pos)
{
	t_spr	*spr;

	spr = ft_spr_get(app, pos);
	if (spr == NULL)
	{
		spr = malloc(sizeof(t_spr));
		if (spr != NULL)
		{
			st_spr_initialize(spr);
			ft_process(app, spr, pos);
		}
	}
	return (spr);
}

static void	ft_process(t_app *app, t_spr *spr, t_pos *pos)
{
	spr->dot.pos_x = pos->pos_x;
	spr->dot.pos_z = pos->pos_z;
	spr->pos.pos_x = ((int) spr->dot.pos_x << 6) + 32;
	spr->pos.pos_z = ((int) spr->dot.pos_z << 6) + 32;
	spr->distance = ft_hypot(app->gme.pos.pos_x, app->gme.pos.pos_z,
			spr->pos.pos_x, spr->pos.pos_z);
	spr->ply_angle = ft_fix_angle(atan2(-1
				* (spr->pos.pos_z - app->gme.pos.pos_z),
				spr->pos.pos_x - app->gme.pos.pos_x));
	spr->fov_angle = ft_fix_angle(app->gme.angle + (30 * RADIAN)
			- spr->ply_angle);
	spr->pos_s.pos_x = spr->fov_angle * (app->win.size_w / (60 * RADIAN));
	spr->pos_s.pos_z = app->win.size_h_d2;
	spr->total_h = 64 / spr->distance * app->rdr.screen_dst;
	ft_lstadd_front(&app->rdr._sprs, ft_lstnew((void *) spr));
}
