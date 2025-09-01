/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:01:01 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 19:35:31 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_parse_read() :
*
*
*/
t_rt	ft_parse_read(t_app *app)
{
	ft_memcpy(&app->prs.old, &app->prs.new, sizeof(t_lne));
	ft_memcpy(&app->prs.new, &app->prs.nxt, sizeof(t_lne));
	if (ft_read(app->prs.ptr.file_descriptor, app->prs.nxt.buffer, '\n', -1)
		> -1)
	{
		app->prs.nxt.length = ft_strlen(app->prs.nxt.buffer);
		if (app->prs.ptr.pos_y == -1 && app->prs.nxt.length == 0)
			return (ft_parse_abort(app, 0.04));
		if (app->prs.ptr.pos_y >= 0 && app->prs.nxt.length == 0)
			app->prs.is_complete = TRUE;
		else if (app->prs.nxt.buffer[app->prs.nxt.length - 1] == '\n')
			app->prs.nxt.buffer[app->prs.nxt.length-- - 1] = '\0';
		app->prs.ptr.pos_x = 0;
		app->prs.ptr.pos_y += 1;
		return (SUCCESS);
	}
	return (ft_parse_abort(app, 0.03));
}
