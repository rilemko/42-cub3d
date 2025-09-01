/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tkn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:42:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/07/03 20:25:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	st_tkn_clear(void *tkn)
{
	st_rgb_clear(&((t_tkn *) tkn)->rgb);
	ft_free((void *) tkn);
}

void	st_tkn_initialize(t_tkn *tkn)
{
	tkn->code = 0.00;
	tkn->count_index = 0;
	tkn->is_colored = FALSE;
	ft_bzero(tkn->token, MAX_CODE_SIZE);
	st_rgb_initialize(&tkn->rgb);
}
