/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:24:49 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/20 02:42:39 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render(t_app *app)
{
	t_lst	*lst;

	if (app->rdr.sts.is_running == FALSE)
		return (ft_window_close(app, &app->win));
	else if (app->rdr.is_updated == FALSE)
	{
		lst = app->_rdrs;
		while (lst != NULL)
		{
			((void (*)())lst->content)(app);
			lst = lst->next;
		}
		app->rdr.is_updated = TRUE;
		app->rdr.updated_at = app->mlx.timestamp;
	}
}
