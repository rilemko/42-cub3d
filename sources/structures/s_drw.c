/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_drw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/05 22:18:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_drw_clear(t_drw *drw)
{
	st_rgb_clear(&drw->rgb);
	st_pos_clear(&drw->pos_t);
	st_pos_clear(&drw->pos_s);
}

void	st_drw_initialize(t_drw *drw)
{
	drw->index_1 = 0;
	drw->index_2 = 0;
	drw->ratio_depth = 0.00;
	drw->ratio_scale = 0.00;
	drw->s = 0;
	drw->s_d2 = 0;
	st_pos_initialize(&drw->pos_s);
	st_pos_initialize(&drw->pos_t);
	st_rgb_initialize(&drw->rgb);
}
