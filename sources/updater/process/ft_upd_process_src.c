/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upd_process_src.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:35:38 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/20 18:26:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_upd_process_src(t_app *app)
{
	t_lst	*lst;

	if (app->mlx.timestamp - app->rdr.animate_at
		>= app->cfg.delay_animation)
	{
		lst = app->_srcs;
		while (lst != NULL)
		{
			if (((t_src *) lst->content)->_texs != NULL)
			{
				((t_src *) lst->content)->_texs
					= ((t_src *) lst->content)->_texs->next;
			}
			lst = lst->next;
		}
		app->rdr.animate_at = app->mlx.timestamp;
		app->rdr.is_updated = FALSE;
	}
}
