/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:55:44 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 22:53:59 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rt	ft_fread(const char *filename, char *buffer)
{
	t_fd	file_descriptor;
	t_rt	status;

	status = FAILURE;
	if (ft_fopen(filename, &file_descriptor, "r") == SUCCESS)
	{
		status = ft_read(file_descriptor, buffer, -1, -1);
		ft_close(file_descriptor);
	}
	return (status);
}
