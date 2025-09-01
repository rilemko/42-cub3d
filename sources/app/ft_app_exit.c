/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_app_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:31:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 22:23:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_app_exit() :
*
*	Clean up the application, write { content } to STDOUT_FILENO stream and
*	exit program with return status { code }.
*/
void	ft_app_exit(t_app *app, int code, const char *content)
{
	st_app_clear(app);
	ft_exit(code, content);
}

/*
*	ft_app_exit_failure() :
*
*	Clean up the application, write { content } to STDERR_FILENO stream and
*	exit program with return status EXIT_FAILURE (1).
*/
void	ft_app_exit_failure(t_app *app, const char *content)
{
	st_app_clear(app);
	ft_exit(EXIT_FAILURE, content);
}

/*
*	ft_app_exit_success() :
*
*	Clean up the application, write { content } to STDOUT_FILENO stream and
*	exit program with return status EXIT_FAILURE (0).
*/
void	ft_app_exit_success(t_app *app, const char *content)
{
	st_app_clear(app);
	ft_exit(EXIT_SUCCESS, content);
}
