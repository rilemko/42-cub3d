/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/19 16:54:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_ptr_clear(t_ptr *ptr)
{
	ft_close(ptr->file_descriptor);
}

void	st_ptr_initialize(t_ptr *ptr)
{
	ptr->file_descriptor = -1;
	ft_bzero(ptr->filename, MAX_PATH_SIZE);
	ptr->pos_x = -1;
	ptr->pos_y = -1;
}
