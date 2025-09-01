/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:32:45 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/26 21:20:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bt	ft_read(t_fd file_descriptor, char *buffer, char delimiter, int size)
{
	t_bt	bytes;
	size_t	buffer_len;

	if (file_descriptor >= 0 && buffer != NULL)
	{
		buffer_len = 0;
		ft_bzero(buffer, 1);
		while (size-- != 0)
		{
			bytes = read(file_descriptor, &buffer[buffer_len], 1);
			ft_bzero(&buffer[buffer_len + 1], 1);
			if (bytes == -1)
				return (FAILURE);
			if (bytes == 0
				|| (delimiter > -1 && buffer[buffer_len] == delimiter))
				break ;
			buffer_len += 1;
		}
		return (buffer_len);
	}
	return (FAILURE);
}
