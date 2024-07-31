/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:35:40 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/04 15:38:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_00(t_app *app)
{
	t_rgb	rgb;

	ft_r00_process_cel(app, ft_memcpy(&rgb, ft_src_rgb(app, 1), sizeof(t_rgb)));
	ft_r00_process_flr(app, ft_memcpy(&rgb, ft_src_rgb(app, 2), sizeof(t_rgb)));
}
