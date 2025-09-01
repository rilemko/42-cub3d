/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:08:10 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 18:48:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rt	ft_write(t_fd file_descriptor, const char *content)
{
	if (file_descriptor >= 0 && content != NULL && ft_strlen(content) > 0
		&& write(file_descriptor, content, ft_strlen(content)) != FAILURE)
		return (SUCCESS);
	return (FAILURE);
}
