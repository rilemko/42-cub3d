/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ext.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/26 16:40:56 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_ext_clear(t_ext *ext)
{
	(void) ext;
}

void	st_ext_initialize(t_ext *ext)
{
	ext->code = EXIT_SUCCESS;
	ft_bzero(ext->content, MAX_BUFF_SIZE);
	ext->is_set = FALSE;
}
