/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:45:43 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/04 15:02:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_parse_open() :
*
*	Resolve the path { filename } by prefixing if necessary with the path of
*	the maps and open the file for reading.
*/
t_rt	ft_parse_open(t_app *app)
{
	if (app->arg.agv[1] != NULL && ft_strlen(app->arg.agv[1]) > 0)
	{
		ft_parse_path(app->prs.ptr.filename, app->cfg.folder_maps,
			app->arg.agv[1]);
		if (ft_fopen(app->prs.ptr.filename, &app->prs.ptr.file_descriptor,
				"r") == SUCCESS)
			return (SUCCESS);
	}
	return (ft_parse_abort(app, 0.02));
}
