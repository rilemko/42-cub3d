/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:42:04 by vpolojie          #+#    #+#             */
/*   Updated: 2023/08/05 18:08:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_ray_clear(t_ray *ray)
{
	ft_free((void *) ray->hits);
	st_pos_clear(&ray->pos);
	st_pos_clear(&ray->map);
}

void	st_ray_initialize(t_ray *ray, t_gme *gme)
{
	ray->angle = ft_fix_angle(gme->angle + (30 * RADIAN));
	ray->count = 0;
	ray->offset_t = 0;
	ray->hit = FALSE;
	ray->hits = NULL;
	ray->target_tpe = 0;
	st_dst_initialize(&ray->dst);
	st_pos_initialize(&ray->map);
	st_pos_initialize(&ray->pos);
	ray->pos.pos_x = gme->pos.pos_x;
	ray->pos.pos_z = gme->pos.pos_z;
}
