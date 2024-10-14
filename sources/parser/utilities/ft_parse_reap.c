/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_reap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:54:38 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 20:28:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_parse_reap() :
*
*
*/
void	ft_parse_reap(t_app *app, char *buffer)
{
	size_t	index;

	index = app->prs.ptr.pos_x;
	ft_parse_skip(app, FALSE);
	while (app->prs.new.buffer[index] != '\0'
		&& app->prs.new.buffer[index] != ' ')
	{
		*buffer++ = app->prs.new.buffer[index++];
		*buffer = '\0';
	}
}
