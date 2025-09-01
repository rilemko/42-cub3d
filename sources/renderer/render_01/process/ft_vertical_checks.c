/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:49:02 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/07 11:49:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_hit(t_app *app, t_ray *ray, t_gme *gme);
static void	ft_check_hit_process(t_app *app, t_ray *ray, t_gme *gme);

void	ft_verticals_rays(t_app *app, t_ray *ray, t_gme *gme)
{
	if ((ray->angle < PI_D2P0 && ray->angle > 0)
		|| (ray->angle > PI_X1P5 && ray->angle < PI_X2P0))
	{
		ray->pos.pos_x = (((int) gme->pos.pos_x >> 6) << 6) + 64;
		ray->pos.pos_z = gme->pos.pos_z + (gme->pos.pos_x - ray->pos.pos_x)
			* tan(ray->angle);
		ray->offset_x = 64;
		ray->offset_y = -ray->offset_x * tan(ray->angle);
	}
	else if ((ray->angle > PI_D2P0 && ray->angle < PI)
		|| (ray->angle < PI_X1P5 && ray->angle > PI))
	{
		ray->pos.pos_x = (((int) gme->pos.pos_x >> 6) << 6) - 0.001;
		ray->pos.pos_z = gme->pos.pos_z + ((gme->pos.pos_x - ray->pos.pos_x)
				* tan(ray->angle));
		ray->offset_x = -64;
		ray->offset_y = -ray->offset_x * tan(ray->angle);
	}
	else
	{
		ray->pos.pos_x = gme->pos.pos_x;
		ray->pos.pos_z = gme->pos.pos_z;
		ray->hit = TRUE;
	}
	ft_check_hit(app, ray, gme);
}

static void	ft_check_hit(t_app *app, t_ray *ray, t_gme *gme)
{
	while (ray->hit == FALSE)
	{
		ray->map.pos_x = (((int) ray->pos.pos_x >> 6));
		ray->map.pos_z = (((int) ray->pos.pos_z >> 6));
		if ((ray->map.pos_x < 0 || ray->map.pos_z > (int) gme->map.size_h - 1)
			|| (ray->map.pos_z < 0 || ray->map.pos_x
				> (int) ft_strlen(gme->map.map[(int) ray->map.pos_z])))
		{
			ray->hit = TRUE;
		}
		else
			ft_check_hit_process(app, ray, gme);
	}
}

static void	ft_check_hit_process(t_app *app, t_ray *ray, t_gme *gme)
{
	int	code;

	code = ft_tkn_use(app,
			gme->map.map[(int) ray->map.pos_z][(int) ray->map.pos_x]);
	if (code == 3 || code == 4)
	{
		ray->dst.dist_vx = ray->pos.pos_x;
		ray->dst.dist_vz = ray->pos.pos_z;
		ray->dst.dist_v = ft_hypot(gme->pos.pos_x, gme->pos.pos_z,
				ray->dst.dist_vx, ray->dst.dist_vz);
		ray->hit = TRUE;
	}
	else
	{
		if (code == 6)
			ft_spr_add(app, &ray->map);
		ray->pos.pos_x += ray->offset_x;
		ray->pos.pos_z += ray->offset_y;
	}
}
