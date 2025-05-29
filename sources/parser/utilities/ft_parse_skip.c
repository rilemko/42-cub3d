/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:55:32 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 19:47:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_parse_skip() :
*
*
*/
void	ft_parse_skip(t_app *app, t_bool inner)
{
	while (inner == TRUE
		&& app->prs.new.buffer[app->prs.ptr.pos_x] != '\0'
		&& app->prs.new.buffer[app->prs.ptr.pos_x] != ' ')
		app->prs.ptr.pos_x++;
	while (app->prs.new.buffer[app->prs.ptr.pos_x] != '\0'
		&& app->prs.new.buffer[app->prs.ptr.pos_x] == ' ')
		app->prs.ptr.pos_x++;
}
