/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/20 00:02:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_dst_clear(t_dst *dst)
{
	(void) dst;
}

void	st_dst_initialize(t_dst *dst)
{
	dst->dist_h = 0.00;
	dst->dist_hx = 0.00;
	dst->dist_hz = 0.00;
	dst->dist_v = 0.00;
	dst->dist_vx = 0.00;
	dst->dist_vz = 0.00;
}
