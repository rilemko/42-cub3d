/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:25:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 20:59:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
*	ft_parse_path() :
*
*
*/
void	ft_parse_path(char *buffer, const char *prefix, const char *filename)
{
	if (filename[0] != '.' && filename[0] != '/'
		&& ft_strncmp(filename, prefix, ft_strlen(prefix)) != 0
		&& ft_exists(filename) == FALSE)
	{
		ft_strlcat(buffer, prefix, MAX_PATH_SIZE);
		ft_strlcat(buffer, "/", MAX_PATH_SIZE);
	}
	ft_strlcat(buffer, filename, MAX_PATH_SIZE);
	if (ft_exists(buffer) == FALSE)
		ft_strlcpy(buffer, filename, MAX_PATH_SIZE);
}
