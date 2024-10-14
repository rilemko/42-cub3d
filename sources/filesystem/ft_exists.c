/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:05:01 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 22:53:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_exists(const char *filename)
{
	t_fd	file_descriptor;

	if (ft_fopen(filename, &file_descriptor, "r") == SUCCESS)
	{
		ft_close(file_descriptor);
		return (TRUE);
	}
	return (FALSE);
}
