/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rdr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/04 01:34:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_rdr_clear(t_rdr *rdr)
{
	ft_lstclear(&rdr->_sprs, st_spr_clear);
	st_sts_clear(&rdr->sts);
	st_ray_clear(&rdr->ray);
	st_hud_clear(&rdr->hud);
}

void	st_rdr_initialize(t_rdr *rdr, t_cfg *cfg, t_gme *gme)
{
	rdr->_sprs = NULL;
	rdr->animate_at = 0.00;
	rdr->content = NULL;
	rdr->is_updated = TRUE;
	rdr->screen_dst = cfg->win_size_w / 2 / tan(30 * RADIAN);
	rdr->updated_at = 0.00;
	st_hud_initialize(&rdr->hud, cfg);
	st_ray_initialize(&rdr->ray, gme);
	st_sts_initialize(&rdr->sts);
}
