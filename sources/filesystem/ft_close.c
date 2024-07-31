/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:06:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/25 20:09:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rt	ft_close(t_fd file_descriptor)
{
	if (file_descriptor == -1 || close(file_descriptor) != FAILURE)
		return (SUCCESS);
	return (FAILURE);
}
