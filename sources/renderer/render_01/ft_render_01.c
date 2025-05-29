/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:35:40 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/07 14:01:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_01(t_app *app)
{
	ft_raycasting_loop(app, &app->rdr.ray, &app->gme);
	ft_r01_process_spr(app);
}
