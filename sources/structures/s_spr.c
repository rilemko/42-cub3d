/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_spr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 11:41:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_spr_clear(void *spr)
{
	st_pos_clear(&((t_spr *) spr)->pos_s);
	st_pos_clear(&((t_spr *) spr)->pos);
	st_pos_clear(&((t_spr *) spr)->dot);
	ft_free((void *) spr);
}

void	st_spr_initialize(t_spr *spr)
{
	spr->distance = 0.00;
	spr->fov_angle = 0.00;
	spr->ply_angle = 0.00;
	spr->total_h = 0.00;
	st_pos_initialize(&spr->dot);
	st_pos_initialize(&spr->pos);
	st_pos_initialize(&spr->pos_s);
}
