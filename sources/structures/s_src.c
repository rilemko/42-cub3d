/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_src.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/06/28 01:06:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_src_clear(void *src)
{
	if (((t_src *) src)->_texs != NULL)
		ft_lstget(((t_src *) src)->_texs,
			((t_src *) src)->count_total - 1)->next = NULL;
	ft_lstclear(&((t_src *) src)->_texs, ft_free);
	st_rgb_clear(&((t_src *) src)->rgb);
	ft_free((void *) src);
}

void	st_src_initialize(t_src *src)
{
	src->_texs = NULL;
	src->callback = NULL;
	src->code = 0.00;
	src->count_total = 0;
	src->is_set = FALSE;
	ft_bzero(src->token, MAX_CODE_SIZE);
	st_rgb_initialize(&src->rgb);
}
