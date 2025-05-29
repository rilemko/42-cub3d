/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_abort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/22 19:48:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_app_abort() :
*
*	Initiate program shutdown. The application process will finish the tasks
*	in progress, display the error message corresponding to { code } and
*	return EXIT_FAILURE (1).
*/
t_rt	ft_app_abort(t_app *app, double code)
{
	if (app->ext.is_set == FALSE)
	{
		ft_strlcpy(app->ext.content, "Error\n", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, app->_, MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, " : ", MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, ft_err_use(app, code), MAX_BUFF_SIZE);
		ft_strlcat(app->ext.content, "\n", MAX_BUFF_SIZE);
		app->ext.code = EXIT_FAILURE;
		app->ext.is_set = TRUE;
		app->sts.is_running = FALSE;
	}
	return (FAILURE);
}
