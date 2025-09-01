/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:32:52 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/05 18:12:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_ray_reset(t_app *app, t_ray *ray, t_gme *gme);
static void	ft_ray_process(t_app *app, t_ray *ray, t_gme *gme);
static void	ft_ray_dist(t_ray *ray, t_gme *gme);

void	ft_raycasting_loop(t_app *app, t_ray *ray, t_gme *gme)
{
	ft_ray_reset(app, ray, gme);
	ft_ray_process(app, ray, gme);
}

static void	ft_ray_reset(t_app *app, t_ray *ray, t_gme *gme)
{
	ft_free((void *) ray->hits);
	ray->hits = malloc(sizeof(double) * app->win.size_w);
	ray->angle = ft_fix_angle(gme->angle + (30 * RADIAN));
	ray->count = 0;
	ray->pos.pos_x = gme->pos.pos_x;
	ray->pos.pos_z = gme->pos.pos_z;
}

static void	ft_ray_process(t_app *app, t_ray *ray, t_gme *gme)
{
	while (ray->count < app->win.size_w)
	{
		ray->dst.dist_h = 100000;
		ray->hit = FALSE;
		ft_horizontal_rays(app, ray, gme);
		ray->hit = FALSE;
		ray->dst.dist_v = 100000;
		ft_verticals_rays(app, ray, gme);
		ft_ray_dist(ray, gme);
		if (ray->count == app->win.size_w_d2)
		{
			gme->target_dst = ray->distance;
			gme->target_pos.pos_x = (((int) ray->pos.pos_x >> 6));
			gme->target_pos.pos_z = (((int) ray->pos.pos_z >> 6));
		}
		ft_r01_process_col(app);
		ray->angle = ft_fix_angle(ray->angle - (FOV / app->win.size_w));
		ray->count++;
	}
}

static void	ft_ray_dist(t_ray *ray, t_gme *gme)
{
	if (ray->dst.dist_h < ray->dst.dist_v)
	{
		ray->pos.pos_x = ray->dst.dist_hx;
		ray->pos.pos_z = ray->dst.dist_hz;
		ray->offset_t = (int) ray->pos.pos_x % 64;
	}
	else
	{
		ray->pos.pos_x = ray->dst.dist_vx;
		ray->pos.pos_z = ray->dst.dist_vz;
		ray->offset_t = (int) ray->pos.pos_z % 64;
	}
	ray->distance = ft_hypot(gme->pos.pos_x,
			gme->pos.pos_z, ray->pos.pos_x,
			ray->pos.pos_z) * cos(ray->angle - gme->angle);
	ray->hits[ray->count] = ray->distance;
	ray->target_tpe = gme->map.map[(((int) ray->pos.pos_z >> 6))]
	[(((int) ray->pos.pos_x >> 6))];
}

double	ft_fix_angle(double angle)
{
	if (angle >= PI_X2P0)
		angle -= PI_X2P0;
	else if (angle <= 0)
		angle += PI_X2P0;
	return (angle);
}
