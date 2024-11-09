/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:24:54 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 18:48:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rt	ft_open(const char *filename, t_fd *file_descriptor, int flags)
{
	if (file_descriptor != NULL)
	{
		*(file_descriptor) = open(filename, flags);
		if (*(file_descriptor) != FAILURE)
			return (SUCCESS);
	}
	return (FAILURE);
}
